#include "model.hxx"

#include <catch.hxx>
#include <iostream>


struct Test_access
{
    Model& m;

    ge211::Timer player_timer = m.player_timer;
    ge211::Timer alien_timer = m.alien_timer;
};

TEST_CASE("Hitting an alien")
{
    Model m;
    Test_access t{m};

    double const dt = 1;
    for(int i = 0; i < 120000; i++) {
        m.on_frame(dt);
    }

    CHECK(m.active_player_lasers.empty());

    CHECK(t.player_timer.elapsed_time().seconds() >=
            ge211::Duration(1.5).seconds());

    m.player.x = 100;
    m.player_shoot_laser();

    CHECK_FALSE(m.active_player_lasers.empty());

    m.aliens.clear();
    m.aliens.push_back({100, 200, m.config.alien_dims().width,
                        m.config.alien_dims().height});

    Laser l = m.active_player_lasers[0];
    l.center.y = 199;
    m.on_frame(dt);

    CHECK(l.hits_alien(m.aliens[0]));

    m.on_frame(dt);

    CHECK(m.game_over);
}

TEST_CASE("Player gets hit"){
    Model m;
    Test_access t{m};

    m.aliens.clear();
    m.shields.clear();
    m.aliens.push_back({m.player.x + m.player.width/2,
                        m.player.y - 100, m.config.alien_dims().width,
                        m.config.alien_dims().height});

    CHECK_FALSE(m.aliens.empty());

    double const dt = 1;
    for(int i = 0; i < 1300000; i++) {
        m.on_frame(dt);
    }

    CHECK(t.alien_timer.elapsed_time().seconds() >=
          ge211::Duration(1.5).seconds());

    m.alien_shoot_laser();

    m.player.x = 100;

    AlienLaser al = m.active_alien_lasers[0];
    al.center.x = m.player.center().x;
    al.center.y = m.player.y - 1;

    m.on_frame(dt);

    CHECK(al.hits_player(m.player));
    CHECK(m.game_over);

}

TEST_CASE("Shield gets hit")
{
    Model m;

    m.aliens.clear();
    Alien a{m.shields[1].x_,
            m.shields[1].y_ - 1,
            m.config.alien_dims().width,
            m.config.alien_dims().height};
    m.aliens.push_back(a);

    CHECK_FALSE(m.aliens.empty());

    CHECK(m.active_alien_lasers.empty());

    AlienLaser al{a, m.config};

    m.active_alien_lasers.push_back(al);

    CHECK_FALSE(m.active_alien_lasers.empty());

    double const dt = 1;

    for (int i = 0; i < 10; i++) {
        m.on_frame(dt);
    }


    CHECK(al.hits_shield(m.shields[1]));
    CHECK(al.destroy_shield(m.shields));
}

TEST_CASE("Player lose by DEATH") {
    Model m;

    //Some setup (this test checks the player will lose the game when they lose
    // their lives)
    m.shields.clear();
    m.aliens.clear();
    m.aliens.push_back({100, 200, m.config.alien_dims().width,
                        m.config.alien_dims().height});
    m.player_lives = 1;
    m.player.x = 100;
    m.player.y = 100;
    for(int i = 0; i < 200000; i++) {
        m.on_frame(1);
    }
    m.alien_shoot_laser();

    //  Creating new alien laser after cooldown has elapsed, then running frames
    //  and checking for collision
    AlienLaser l{m.aliens[0], m.config};
    m.active_alien_lasers.push_back(l);
    m.active_alien_lasers[0].center.y = 100;
    for(int i = 0; i < 100; i++) {
        m.on_frame(1);
    }


    //Checks that the game is over
    CHECK(m.game_over);
    //Check that the player is set as the loser
    CHECK_FALSE(m.player_win);



}
TEST_CASE("alien movement check + lose at bottom") {

    //THIS TEST CHECKS THAT (1) ALIENS MOVE AND SHIFT DOWN PROPERLY, AND THAT
    // (2) THE PLAYER LOSES IF THE ALIENS REACH THE BOTTOM
    Model m;

    m.shields.clear();
    //Setting the alien right next to the edge of the screen
    m.aliens.push_back({1024 - m.config
                                .alien_dims().width,
                        m.player.y - 1, m.config.alien_dims().width,
                        m.config.alien_dims().height});
    //This runs 100 frames, which will make sure that the alien moves to the
    // right AND that it shifts down at the edge
    for(int i = 0; i < 200000; i++) {
        m.on_frame(1);
    }
    //Check that the aliens are below the player (lose condition)
    CHECK(m.aliens[0].y_ + m.aliens[0].height_ >= m.player.y );
    //Check that the game is set to be over
    CHECK(m.game_over);
    //Check that the player is set as the loser
    CHECK_FALSE(m.player_win);
}