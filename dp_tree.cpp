#include <iostream>

using namespace std;

int tree_count_mem[1000] = { 1, 1, 2, 0, };
int known_idx = 2;

int tree_count(int num) {
	if (num <= known_idx)
		return tree_count_mem[num];

	for (int i = known_idx + 1; i <= num; i++) {
		for (int j = 1; j <= i; j++) {
			tree_count_mem[i] += tree_count_mem[i - j] * tree_count_mem[j - 1];
		}
	}
	known_idx = num;
	return tree_count_mem[num];
}

int main() {
	for (int i = 0 ; i < 10; i++)
		cout << "tree count : " << tree_count(i) << endl;
}