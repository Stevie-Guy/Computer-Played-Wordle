# Computer-Played-Wordle
A wordle game played by the computer.

## Software used for this project
- Visual Studio Code version: 1.77.0
- Compiler: gcc (MinGW.org GCC-6.3.0-1) 6.3.0

## About the project
This is a classic wordle game but instead of a player playing the game, the computer is trying to guess the word. I made this project because a friend of mine had to do it for University and I wanted to try it out too. The code is not 100% perfect, sometimes the computer doesn't guess the word because of the multiple words (3 or more) having only 1 letter different from each other.

## How it works
- After you run the code the computer chooses a word from `wordle.txt` using the program `randcuv.hpp`
- After choosing the word, the computer tries to guess the word, the first try will always be the first word in the `wordle.txt` file
- Then the computer uses the information that it collected from the previous try to make better and better guesses, like a player would
- The game ends either when the computer guesses the word(90% of the times) or when it runs out of chances (it has 6)
