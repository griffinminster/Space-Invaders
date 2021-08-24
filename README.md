# Space-Invaders

A basic version of Space Invaders created for Northwestern University CS211. Designed and executed with Jack Burkhardt.

Programmed in C++ and rendered using ge211, an engine made by Professor Jesse Tov using the SDL2 libraries.


Design specifications:
    The aliens are initially placed in a large grid near the top of the screen
    The aliens, as a whole block, move slowly to one side of the screen, move down, and then continue to the other side of the screen.
    The player’s ship is y-locked near the bottom of the screen, but can move back and forth using the left and right arrow keys. There will be continuous control — If the user holds down either of the arrow keys, the ship should continue to move in that direction.
    The player can shoot a laser directly up using the spacebar, but there is a brief “cooldown” period between shots
    The aliens also shoot lasers straight downwards, often hitting shields in the process. (In play testing, if this makes the game too easy, the shots can be targeted at the player)
    If an alien is hit, it disappears from the screen
    If the player is hit, you lose a life. 3 lives lost is game over. The life count will be displayed with a few small icons in the corner of the screen. Every time the player’s ship is destroyed, one of the icons will disappear.
    After losing a life, the player will respawn in the center of the screen. The ship will appear destroyed through a different image or animation for a few seconds, but then will immediately respawn without any invincibility frames.
    There are a few “shields” directly above the player, near the bottom of the screen. They can take a few (TBD) hits from both the aliens and the player to protect the player, but eventually break once their hit-count is depleted. The shields are unmoving arches.
    If the aliens reach the bottom of the screen – the player’s y-position – it is game over
    A simple point system keeps track of the player’s score for hitting the aliens



https://d33wubrfki0l68.cloudfront.net/b440f84f87b8a62fd29741e90a45e60db74b52e9/6e44e/resources/spaceinvaders/mainscreen.png
https://d33wubrfki0l68.cloudfront.net/cd490d3e472e94900422eeeb17971ac39ff3d943/4b867/resources/spaceinvaders/explode.png
https://d33wubrfki0l68.cloudfront.net/35cd21cb4894a63f4cc77c761953744c4fd13ee0/521e0/resources/spaceinvaders/lategame.png
https://d33wubrfki0l68.cloudfront.net/397e65b2b369391600a4012436b2f1d0989144e4/ca219/resources/spaceinvaders/lose.png
https://github.com/jackburkhardt/ge211-spaceinvaders/blob/main/ge211.gif
