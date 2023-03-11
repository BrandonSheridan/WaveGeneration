#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void generateFirstGrid(void) {

	int grid[9][9];
	int nums[9];

	for (int i = 0; i < 9; ++i){
		nums[i] =  
	}

	// FILE *fopen(file, w+);

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
				grid[(j / 3) + (i / 3)][(j % 3) + (i % 3)] = ;
				printf("%d", grid[(j / 3) + (i / 3)][(j % 3) + (i % 3)]);
		}
		printf("\n");
	}

}

int main(void) {

	generateFirstGrid();

	return 0;
}

