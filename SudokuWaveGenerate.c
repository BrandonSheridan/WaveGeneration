#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//globals
int solvedGrid[9][9]; //[rows][collumns]
time_t seed;
FILE * out;

//fun prototypes
void initGrid(void);
void printGrid(void);
void generateGrid(void);
int recurseGen(int xPos, int yPos);
int * checkInvalidNums(int xPos, int yPos);
int cmpNum(int * numArr, int num);

int main(int argc, char * argv[]) {
	initGrid();
	seed = time(NULL); 
	
	
	if (argv[1] == NULL) {
		printf("no target file specified\n");
		exit(-1);
	}
	out = fopen(argv[1], "w");
	
	int isDone;
	do {
		initGrid();
		srand(seed);
		isDone = recurseGen(0, 0);
		seed *= (seed + 1);
	} while (isDone <= 0);

	printGrid();
	// free(numArr);
	// fclose(out);

	return 0;
}

void printGrid(void) {		// prints grid matrix to terminal
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j){
			if (!(j % 3) && j != 0)
				printf("| ");
			printf("%d ", solvedGrid[i][j]);
			fprintf(out, "%d", solvedGrid[i][j]);
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

// void generateGrid() {	// gets generation started by inserting a starting val and calling the recursion function
// 	solvedGrid[0][0] = (rand() % 9 ) + 1;
// 	recurseGen(1, 0);printf("returning from generategrid1\n");
// 	recurseGen(0, 1);printf("returning from generategrid2\n");
		
// 	return;
// }

int recurseGen(int xPos, int yPos){
	int returnVal = 0;
	
	if (solvedGrid[xPos][yPos] > 0) return 0;

	int * numArr = checkInvalidNums(xPos, yPos);
	
	if (numArr == NULL){
		free(numArr);
		return -1; 
	}
	int flag, randNum; //set flag to 0 if a value that is valid is stored
	
	do {
		randNum = (rand() % 9) + 1;
		flag = cmpNum(numArr, randNum);
	} while (flag == 1);

	free(numArr);

	solvedGrid[xPos][yPos] = randNum;


	if (xPos == 0 && yPos == 8){
		return 1;
		}

	if (xPos < 8) {
		returnVal += recurseGen(xPos + 1, yPos);
	}

	if (yPos < 8) {
		returnVal += recurseGen(xPos, yPos + 1);
	}

	return returnVal;
}

int * checkInvalidNums(int xPos, int yPos) {
	int * numArr = malloc(9 * sizeof(int));
	if (numArr == NULL){
		printf("malloc failed, exiting\n");
		exit(1);
	}
	for (int i = 0; i < 9; ++i) { //init array
		numArr[i] = 0;
	}

	for (int i = 0; i < 9; ++i){
		if (solvedGrid[i][yPos] != 0){
			numArr[solvedGrid[i][yPos] - 1] = 1;
		}
	}

	for (int i = 0; i < 9; ++i){
		if (solvedGrid[xPos][i] != 0){
			numArr[solvedGrid[xPos][i] - 1] = 1;
		}
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (solvedGrid[i + xPos - (xPos % 3)][j + yPos - (yPos % 3)] != 0){
				numArr[solvedGrid[i + xPos - (xPos % 3)][j + yPos - (yPos % 3)] - 1] = 1;
			}
		}
	}

	// printGrid();

	for (int i = 0; i < 9; ++i){
		if(numArr[i] == 1){}
		else {
			return numArr;
		}
	} 
	free(numArr);
	// printf("invalid grid: retrying\n");
	return NULL;
}

int cmpNum(int * numArr, int num) {
	// printf("%d\n", num);
	for (int i = 0; i < 9; ++i) {
		if (i + 1 == num && numArr[i] == 1) return 1;
	}

	return 0;
}