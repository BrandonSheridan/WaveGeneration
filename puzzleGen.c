#include <stdio.h>
#include <stdlib.h>

//globals
FILE * in;
FILE * out;
int solved[9][9];
int puzzle[9][9];

//fun prototypes
void init(int ** grid);

int main() {
    init(puzzle);

    return 0;
}

void init(int ** grid) {
    for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j){
			grid[i][j] = 0;
		}
	}
}