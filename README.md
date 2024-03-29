# Space Invaders

A basic version of Space Invaders created for Northwestern University CS211. Designed and executed with Jack Burkhardt.

Programmed in C++ in CLion and rendered using ge211, an engine made by Professor Jesse Tov using the SDL2 libraries.


### Design specifications:
- The aliens are initially placed in a large grid near the top of the screen
- The aliens, as a whole block, move slowly to one side of the screen, move down, and then continue to the other side of the screen.
- The player’s ship is y-locked near the bottom of the screen, but can move back and forth using the left and right arrow keys. There will be continuous control — - If the user holds down either of the arrow keys, the ship should continue to move in that direction.
- The player can shoot a laser directly up using the spacebar, but there is a brief “cooldown” period between shots
- The aliens also shoot lasers straight downwards, often hitting shields in the process.
- If an alien is hit, it disappears from the screen
- If the player is hit, you lose a life. 3 lives lost is game over. The life count will be displayed with a few small icons in the corner of the screen. Every time the player’s ship is destroyed, one of the icons will disappear.
- After losing a life, the player will respawn in the center of the screen. The ship will appear destroyed through a different image or animation for a few seconds, but then will immediately respawn without any invincibility frames.
- There are a few “shields” directly above the player, near the bottom of the screen. They can take a few hits from both the aliens and the player to protect the player, but eventually break once their hit-count is depleted. The shields are unmoving arches.
- If the aliens reach the bottom of the screen – the player’s y-position – it is game over
- A simple point system keeps track of the player’s score for hitting the aliens



![Space Invaders Gameplay](https://github.com/griffinminster/Space-Invaders/blob/b31135284406f26054744ba7c758b45d896bbe89/Space%20Invaders%20Gameplay.gif)
![mainscreen](https://user-images.githubusercontent.com/69056215/130668430-67dd83a2-a8f1-4007-907f-bac10d7e8da8.png)
![explode](https://user-images.githubusercontent.com/69056215/130668438-1cd28a46-3770-41d3-92e9-057945078533.png)
![lategame](https://user-images.githubusercontent.com/69056215/130668447-99e5dcdb-7ddd-4456-86e0-517c83cc2275.png)
![lose](https://user-images.githubusercontent.com/69056215/130668460-7c3c9484-37d8-46c0-af97-0127e4d8225a.png)


