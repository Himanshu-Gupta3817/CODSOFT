# Number Guessing Game

This is a simple number guessing game implemented in C++. In this game, a random number between 1 and 100 is generated, and the player has to guess the correct number. The game provides feedback on whether the guess is too high or too low, and the player has a limited number of choices based on the chosen difficulty level.

## Gameplay Screenshot

![Gameplay Screenshot](Number Guessing Game 1.png)
![Gameplay Screenshot](Number Guessing Game 2.png)

## How to Play

1. Run the program in a C++ environment.
2. The game will display a welcome message and instructions.
3. Choose a difficulty level:
   - Enter `1` for easy (10 choices).
   - Enter `2` for medium (7 choices).
   - Enter `3` for difficult (5 choices).
   - Enter `0` to exit the game.
4. Guess the number by entering your choice.
5. The program will provide feedback on whether your guess is too high or too low.
6. Keep guessing until you find the correct number or run out of choices.
7. If you guess the correct number, you win!
8. After each game, you can choose to continue playing or exit the game.

## Code Overview

**Technical Skills Implemented (Programming Language: C++)**

- **Random Number Generation:** The code, written in C++, uses the `srand` and `rand` functions to generate a random number within a specified range.

- **Looping:** It implements a game loop using a `while` loop to allow the player to make multiple guesses until they win or run out of choices.

- **User Input:** The code takes user input for guessing the number and handles user interaction.

- **Conditional Statements:** It uses `if-else` statements to provide feedback on the player's guess and determine game outcomes.

- **Functions:** The code is organized into functions, with a `numberGuessing` function handling the core game logic and a `main` function providing the game's interface.

## Code Structure

The code consists of two main functions:

1. `void numberGuessing(int choicesLeft)`: This function handles the game logic for a given number of choices. It generates a random number and asks the user to guess it.

2. `int main()`: This is the main function that provides the game's interface. It allows the player to choose a difficulty level, play the game, and decide whether to continue playing.

## How to Compile and Run

To compile and run the code, you need a C++ development environment. Here are the steps:

1. Save the code to a file with a `.cpp` extension (e.g., `number_guessing_game.cpp`).
2. Open a terminal or command prompt.
3. Navigate to the directory where the code is saved.
4. Compile the code using a C++ compiler (e.g., g++): `g++ -o number_guessing_game number_guessing_game.cpp`
5. Run the compiled executable: `./number_guessing_game`

## Enjoy the Game!

Have fun playing the Number Guessing Game! Try to guess the correct number within the given choices and challenge yourself with different difficulty levels. This game not only provides entertainment but also showcases fundamental programming skills, including random number generation, user input handling, and conditional statements. Good luck and enjoy the game!

## Contributor

- **Himanshu Gupta**