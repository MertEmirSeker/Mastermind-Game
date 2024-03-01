# Mastermind Game

This C++ program is a command-line game where the player tries to guess a secret number. The game offers two modes: a random mode where the game generates a secret number, and a user-defined mode where the player can specify the secret number.

## Features

- Two game modes: random secret number (`-r`) and user-defined secret number (`-u`).
- Input validation for guessing only valid numbers and adhering to the specified number of digits.
- Feedback provided for each guess, indicating the count of exactly matched digits and misplaced but correct digits.
- Error handling for invalid inputs and commands.

## Compilation and Execution

Compile the program with `g++ -o mastermind_game main.cpp`. To run the game in random mode with a 4-digit number, use `./mastermind_game -r 4`. For user-defined mode, use `./Mastermind_game -u 1234` where `1234` is your secret number.

## Gameplay

1. Start the game in one of the two modes.
2. The program will prompt for guesses. Enter a guess that matches the number of digits specified.
3. After each guess, you'll receive feedback on the number of exact matches and misplaced matches.
4. The game continues until the secret number is guessed correctly or if an error occurs due to invalid input.

Enjoy the challenge and try to guess the secret number with the fewest attempts!
