# Stacks and Queues
A puzzle game based on the mechanics of the abstract data structures Stacks and Queues.

### Current Game: version 0.1 ###

#### Concepts ####

Stack: A stack or LIFO (last in, first out) is an abstract data type that serves as a collection of elements, with two principal operations: push adds an element to the collection; pop removes the last element that was added. This game uses another operation of a stack: peek, which shows the last element that was added without removing it.

Queue: In a queue or a FIFO data structure, the first element added to the queue will be the first one to be removed. Enqueue is used to add an element to the collection and dequeue is used to remove. Peek or front is used to show the first element to be added without removing it.

#### Description ####

Each level starts with a line of balls entering the screen from the right hand side in a specific starting order. They always follow a main yellow line that spans across the screen from one tube (the right hand side input tube from which the balls enter the screen) to another (an exit tube that is always directly opposite to the input tube). There are detours from this main yellow path that can lead to other structures like stacks. The goal of the player is to rearrange that starting order with the use of the onscreen structures. The vertical structures are stacks (currently orange rectangles) and queues are meant to be horizontal structures (Coming Soon). 

When a ball encouters a stack by coming close to the point where the stack touches the yellow path, it is automatically pushed into the stack and stored. Stacks have a capacity greater than the number of balls onscreen so the player won't have to worry about running out of space. The player can peek at the top ball of the stack or pop it out and have it resume it's journey on the yellow path by clicking on the stack with the right or left mouse buttons respectively. If the player satisfies the order displayed on the purple bar at the bottom of the screen, the level is won; if not, the player loses.

#### Controls ####

Gameplay keys: 
<br>Q - Selects and highlights green, the ball on the left+.
<br>E - Selects and highlights green,  the ball on the right+.
<br>W - Makes the selected ball move up *.
<br>A - Makes the selected ball move left *.
<br>S - Makes the selected ball move down *.

"+" = according to original order.
<br>"*" = when a path is available. Balls are not allowed to move outside the path, the take the next available turn. This can be overridden by another key press, balls only store one turn direction at a time.

Mouse buttons:
<br>Left mouse - Pops the stack/ Dequeues the queue.
<br>Right mouse - Peek at the stack/ Fronts the queue.

Other:
<br>Esc - Exits the level without saving.
<br>P - Pauses the level.
<br>Enter - Resumes the level if paused. Starts the game if MainMenu screen fails to load and backup Menu is shown.

### Development ###

#### Motivation ####

To make a fun and entertaining puzzle game. Originally intended to provide a more significant educational experience but we have found that it can only currently serve as exposure to these data structures based on user feedback.

#### Technical ####

This game was written mainly in C++ and using SFML, a multimedia API. Bugs and issues are reported on this repository's issues page.

#### Features implemented ####

1. Gameplay and level creation: 
<br>a) Basic AI of the numbered balls. They are able to detect and navigate the yellow path from one tube to another without player input regardless either of the paths they are sent to. They can check if player input for direction change is valid, stores up to one request for direction change and takes the next valid turn.
<br>b) Player controls: keyboard and mouse.
<br>c) Dynamic genration of yellow path using an algorithm that takes note of tube and stack coordinates.
<br>d) Level status bar to show the correct order to win the game. Let's the player know if he won, lost or there was an error with the game.

2. Main menu design and functionality
3. Game can be paused and resumed, as well as exited and restarted.

#### Future planned features ####

1. Queues, we had not been able to implement queues in the previous sprint, but the foundation for the integration of a Queue class and objects have been setup in the other class methods.
2. Level 1 has been completed with only one stack (refer to video). Atleast 2 more levels with increasing difficulty are planned with both stacks and queues included.
3. Help page for player.
4. Music and sound effects. To make the game more engaging.

### Install from source ###

Dependencies : SFML

OSX Xcode: Follow installaton procedure for sfml on Xcode: 
http://www.sfml-dev.org/tutorials/2.0/start-osx.php Set up a .xcodeproj with sfml and add the files from this repository's Stacks and Queues folder to the project. Add Resource files from this repository to the Resource folder. Compile and Build.

Windows Visual Studio: Follow installation procedure for sfml on Visual Studio: http://www.sfml-dev.org/tutorials/2.3/start-vc.php. Set up new project and add files from this repository's Stacks and Queues VS folder. Add Resource folder to project. Compile and Run.
