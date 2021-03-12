#pragma once

#include "model.hxx"
#include "view.hxx"


class Controller : public ge211::Abstract_game
{
public:

    /// Controller constructor
    explicit Controller();

protected:

    /// Draws everything on screen (but functionality is in View::draw()
    void draw(ge211::Sprite_set&) override;

    /// Dimensions of the screen
    ge211::Dims<int> initial_window_dimensions() const override;

    /// Checks behavior for each key of user input
    void on_key(ge211::Key) override;

    /// Calls Model::on_frame() to simulate a frame of gameplay
    void on_frame(double dt) override;


private:
    Model model_;
    View view_;
};