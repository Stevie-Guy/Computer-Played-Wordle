# Computer-Played-Wordle
A wordle game played by the computer.

## Software used for this project
- Visual Studio Code version: 1.77.0
- Compiler: gcc (MinGW.org GCC-6.3.0-1) 6.3.0

## About the project
This is a classic wordle game but instead of a human playing the game, the computer is playing it through reinforcement learning. I made this project because a friend of mine had it as an University project and I wanted to give it a try. The code is not 100% perfect, sometimes the computer doesn't guess the word because of the multiple words (3 or more) having only 1 letter different from each other.

## How to play it
### 1. [Install](https://code.visualstudio.com/download) Visual Studio Code for Windows 10 and the [GCC Compiler](https://sourceforge.net/projects/mingw-w64/)(Windows 10 is necessary). 
### 2. Download all of the files in a single folder.
### 3. Compile and run `joc_wordle.cpp`, then run the `joc_wordle.exe` file that was created in the same folder

## How it works
- When compiling, the computer chooses a word from `wordle.txt`. The algorithm used to choose the word is in `randcuv.hpp`;
- After choosing the word, the computer tries to guess the chosen word. The first try will always be the first word in the `wordle.txt` file;
- Then, the computer uses the information it collected from previous attempts to improve and make better guesses, just like we do. It is reinforcement learning, through trial and error;
- The game ends either when the computer guesses the word(90% of the times) or when it runs out of attempts (it has 6).
