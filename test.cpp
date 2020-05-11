#include <iostream>

using namespace std;
static double dNumList[100] = { 0, };
static char strData[64];
static __int64 iNumList[100] = { 0, };
__int64 dNumber = 1;

static char elements[27];
static int positions[26];
const int max = 1 << 26;

int main() {
	for (int i = 0; i < 26; i++) {
		elements[i] = (char)(((int)'a') + i);
	}
	cout << elements << endl;
	
	for (int i = 0; i < 26; i++) {
		positions[i] = 1 << i;
	}

	cout << "max = " << max << endl;
	int total = 0;
	char target_str[5] = { 'a','b','c','z','y' };
	int count = 0;
	char results[27];
	for (int tmp = 0; tmp < 27; tmp++) {
		results[tmp] = '0';
	}
	results[26] = '\0';

	for (int i = 1; i < max; i++) {
		if ((i & positions[25]) && (i & positions[24]) && (i & positions[2]) && (i & positions[12]) && (i & positions[18]) && (i & positions[1]) && (i & positions[0]) && (i & positions[10])) {
			for (int p = 0; p < 26; p++) {
				if (i & positions[p]) {
					results[p] = elements[p];
				} else {
					results[p] = '-"" ';
				}
			}
			count++;
			//cout << results << endl;
		}		
		for (int tmp = 0; tmp < 26; tmp++) {
			results[tmp] = '0';
		}
		//cout << endl;
	}
	cout << "total count : " << count << endl;

	cout << sizeof(dNumList[0]) << endl;
	cout << sizeof(strData[0]) << endl;
	cout << sizeof(iNumList[0]) << endl;
	cout << "test" << endl;
	__int64 target = 1023;
	__int64 result = 0;
	__int64 tmp = 1;

	for (int i = 0; i < 64; i++) {
		result = target & (tmp<<(63-i));
		if (result > 0) {
			cout << "1";			
			//cout << "i = " << i << ", result : " << result << endl;
		} else {
			cout << "0";
		}
	}
	cout << strData << endl;
}
