#include <iostream>

using namespace std;

float player1[500] = { -1, };
float player2[500] = { -1, };
float opt_cache[500][500] = { 0, };
float diff[500][500] = { -1 };

void init(int p1, int p2) {
	for (int i = 0; i < p1; i++) {
		player1[i] = rand() % 100 + 30;
	}

	for (int j = 0; j < p2; j++) {
		player2[j] = rand() % 100 + 35;
	}
}

void sort(float (&player)[500], int count) {
	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (player[i] > player[j]) {
				int value = player[i];
				player[i] = player[j];
				player[j] = value;
			}
		}
	}
}

int main() {
	int player1_cnt = 22;
	int player2_cnt = 33;
	init(player1_cnt, player2_cnt);
	//for (int i = 0; i < player1_cnt; i++)
	//	cout << "player1 : " << player1[i] << endl;
	//for (int i = 0; i < player2_cnt;i++)
	//	cout << "player2 : " << player2[i] << endl;

	sort(player1, player1_cnt);
	sort(player2, player2_cnt);

	for (int i = 0; i < player1_cnt; i++)
		cout << "player1 : " << player1[i] << endl;
	for (int i = 0; i < player2_cnt; i++)
		cout << "player2 : " << player2[i] << endl;

	for (int i = 0; i < player1_cnt; i++) {
		for (int j = 0; j < player2_cnt; j++) {
			float tmp = player1[i] - player2[j];
			if (tmp < 0)
				tmp *= -1;
			diff[i][j] = tmp;
		}
	}

	for (int i = 0; i < player1_cnt; i++) {
		for (int j = 0; j < player2_cnt; j++) {
			cout << "diff" << i << "," << j << " : " << diff[i][j] << endl;
			
		}
	}

	for (int i = 0; i < player1_cnt; i++) {
		for (int j = 0; j < player2_cnt; j++) {
			if (i > j) {
				opt_cache[i][j] = -1;
			}
			else if (i == j) {
				for (int k = 0; k <= i; k++) {
					opt_cache[i][j] += diff[k][k];
				}
			}
			if (j > i&& i == 0) {
				int tmp = diff[0][0];
				for (int i = 1; i <= j; i++) {
					if (tmp > diff[0][i]) {
						tmp = diff[0][i];
					}
				}
				opt_cache[i][j] = tmp;
			}
		}
	}

	cout << "init" << endl;
	for (int i = 0; i < player1_cnt; i++) {
		for (int j = 0; j < player2_cnt; j++) {
			cout << opt_cache[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 1; i < player1_cnt; i++) {
		for (int j = 1; j < player2_cnt; j++) {
			if (i < j) {
				float tmp1 = opt_cache[i - 1][j - 1] + diff[i][j];
				float tmp2 = opt_cache[i][j - 1];
				if (tmp1 < 0 && tmp2 < 0) {
					opt_cache[i][j] = -1;
				}
				else if (tmp2 < 0) {
					opt_cache[i][j] = tmp1;
				}
				else if (tmp1 < 0) {
					opt_cache[i][j] = tmp2;
				}
				else if (tmp1 > tmp2) {
					opt_cache[i][j] = tmp2;
				}
				else {
					opt_cache[i][j] = tmp1;
				}
			}
		}
	}
	cout << "result" << endl;
	for (int i = 0; i < player1_cnt; i++) {
		for (int j = 0; j < player2_cnt; j++) {
			cout << opt_cache[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "result : " << opt_cache[player1_cnt - 1][player2_cnt - 1] << endl;
}