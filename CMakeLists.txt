cmake_minimum_required(VERSION 3.3)
# TODO: CHANGE THE NEXT LINE TO THE INCLUDE THE TITLE OF YOUR GAME:
project(Space-Invaders CXX)
include(.cs211/cmake/CMakeLists.txt)

# TODO: PUT ADDITIONAL MODEL .cxx FILES IN THIS LIST:
set(MODEL_SRC
        src/model.cxx
        src/game_config.cxx
        src/laser.cxx
        src/shield.cxx
        src/alien.cxx
        src/alien_laser.cxx)

# TODO: PUT ADDITIONAL NON-MODEL (UI) .cxx FILES IN THIS LIST:
add_program(main
        src/main.cxx
        src/view.cxx
        src/controller.cxx
        ${MODEL_SRC})
target_link_libraries(main ge211)

add_test_program(model_test
        test/model_test.cxx
        ${MODEL_SRC})
target_link_libraries(model_test ge211)

# vim: ft=cmake