# WaveGeneration
creates a completed sudoku board by using a wave generation algorithm

to run:
gcc SudokuWaveGenerate.c 
./a.out [desired output file name]

the output will be stored in the file that was passed in in the args at runtime

TODO:
use puzzleGen.c to create a randomized starting position for the puzzle and pass it to SudokuWaveGenerate.c
revize SudokuWaveGenerate.c to test if there is more than 1 solution for the puzzle state

create a GUI to display a sudoku board and normal functionality of a sudoku puzzle application:
clicking on a square allows you to input a number from 1-9
allow numbers to be changed
allow guess numbers to be inputed on a square as a small number in a corner