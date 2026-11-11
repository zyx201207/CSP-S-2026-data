#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int t = 0;
	int c3 = (c1[0] - '0') * 10 + c1[1] - '0';
	int c4 = (c2[0] - '0') * 10 + c2[1] - '0';

	int s3 = (s1[0] - '0') * 10 + s1[1] - '0';
	int s4 = (s2[0] - '0') * 10 + s2[1] - '0';

	char x = s1[2];
	char y = s2[2];
	if (c3 == c4) {
		cout << 1;
		t = 1;
	} else {
		cout << 0;
	}

	if (s3 == s4 && t == 1) {
		cout << 1;
		t = 2;
	} else {
		cout << 0;
	}
	if (t == 2) {
		if ((x == 'D' && y == 'F') || (x == 'F' && y == 'D')) {
			cout << 11;
			return 0;
		} else {
			if ((x >= 'A' && x <= 'C' && y >= 'A' && y <= 'C')) {
				cout << 1;
				t = 3;
			} else {
				cout << 0;
			}
		}
	} else {
		cout << 0;
	}

	int x1 = x;
	int y1 = y;
	int z = abs(x - y);
	if (t == 3 && z == 1) {
		cout << 1;
	} else {
		cout << 0;
	}







	return 0;
}