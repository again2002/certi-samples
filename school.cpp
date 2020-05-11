#include <iostream>

using namespace std;

const int CELL_NO = 100;
const int STATION_NO = 3;
static int cells[CELL_NO][CELL_NO] = { 0, };
static int stations[STATION_NO][2] = { 0, };

int cell_pos[CELL_NO][2];
int cell_info[CELL_NO][5];

int main() {
	int cell_count = 0;
	while(cell_count < CELL_NO){
		int x = rand() % CELL_NO;
		int y = rand() % CELL_NO;
		if (cells[y][x] == 0) {
			cells[y][x] = 1;
			cell_count++;
		}
	}
	cout << "cell count : " << cell_count << endl;

	int station_count = 0;
	while (station_count < STATION_NO) {
		int x = rand() % CELL_NO;
		int y = rand() % CELL_NO;
		if (cells[y][x] == 0) {
			stations[station_count][0] = x;
			stations[station_count][1] = y;
			station_count++;
		}
	}

	for (int y = 0; y < CELL_NO; y++) {
		for (int x = 0; x < CELL_NO; x++) {			
			cout << cells[y][x];
		}
		cout << endl;
	}

}
