#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, a1, b, b1;
	cin >> a >> a1 >> b >> b1;
	int bj = 0;
	for (int i = 0; i < 10; i++) {
		s[i] = '0';
	}
	if (a == b) {
		s[0] = '1';
		bj++;
	}
	if (bj == 1) {
		if (a1[0] == b1[0] && a1[1] == b1[1]) {
			s[1] = '1';
			bj++;
		}
	}
	if (bj == 2) {
		if (b1[2] <= 'C' && a1[2] <= 'C') {
			s[2] = '1';
			bj++;
		}
		if (b1[2] >= 'D' && a1[2] >= 'D') {
			s[2] = '1';
			bj++;
		}
	}

	if (bj == 3) {
		if (a1[2] + 1 == b1[2]) {
			s[3] = '1';
		}
	}
	for (int i = 0; i < 4; i++) {
		cout << s[i];
	}





	return 0;
}