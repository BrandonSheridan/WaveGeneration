#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int solvedGrid[9][9]; //[rows][collumns]


void initGrid(void);
void printGrid(void);
void generateGrid(int startNum, int xPos, int yPos);
void recurseGen(int xPos, int yPos);
int * checkInvalidNums(int xPos, int yPos);

int main(void) {
	initGrid();
	generateGrid(4, 8, 8);
	printGrid();

	return 0;
}

void printGrid(void) {		// prints grid matrix to terminal
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j){
			if (!(j % 3) && j != 0)
				printf("| ");
			printf("%d ", solvedGrid[i][j]);
		}
		if (!((i + 1) % 3) && i != 8)
			printf("\n_____________________\n");
		else
			printf("\n");
	}

}

void initGrid(void) {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j){
			solvedGrid[i][j] = 0;
		}
	}
}

void generateGrid(int startNum, int xPos, int yPos) {	// gets generation started by inserting a starting val and calling the recursion function
	solvedGrid[xPos][yPos] = startNum;
	if (xPos > 0) {
		recurseGen(xPos - 1, yPos);
	}
	if (yPos > 0) {
		recurseGen(xPos, yPos - 1);
	}

}

void recurseGen(int xPos, int yPos){
	// printf("x: %d\ty: %d\n", xPos, yPos);
	int * numArr = checkInvalidNums(xPos, yPos);
	for (int i = 0; i < (sizeof(numArr) / sizeof(int)); ++i){
		printf("%d\t", numArr[i]);
	}
	printf("\n");
}

int * checkInvalidNums(int xPos, int yPos) {
	int * numArr = malloc(0);
	int numOfInvalid = 0;

	for (int i = 0; i < 9; ++i){
		if (solvedGrid[i][yPos] != 0){
			numArr[numOfInvalid] = solvedGrid[i][yPos];
			++numOfInvalid;
			numArr = realloc(numArr, sizeof(int) * numOfInvalid);
			// printf("invalid %d", solvedGrid[i][yPos]);
		}
	}

	return numArr;
}