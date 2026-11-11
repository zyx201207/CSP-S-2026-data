#include <iostream>
#include <string>
using namespace std;

int main() {
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	char x, r;
	x = s1[2];
	r = s2[2];
	int a = 0;
//是否在同一车厢
	if (c1 == c2) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
//是否在同一排
	if (s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}

	cout << 'u';
	if (x == 'A' || r == 'C') {
		cout << "10A";
		return 0;
	}
	if (x == 'C' || r == 'A') {
		if (r == 'D') {
			cout << "00";
			return 0;
		}
		cout << "10B";
		return 0;
	}
	if (x == 'F' || r == 'D') {
		cout << "11";
		return 0;
	}
	if (x == 'D' || r == 'F') {
		cout << "11";
		return 0;
	}
	if (x == 'A' || r == 'B') {
		cout << "11";
		return 0;
	}
	if (x == 'B' || r == 'A') {
		cout << "11";
		return 0;
	}
	if (x == 'C' || r == 'B') {
		cout << "11";
		return 0;
	}
	if (x == 'B' || r == 'C') {
		cout << "11";
		return 0;
	}
	cout << "00";
	return 0;
}

