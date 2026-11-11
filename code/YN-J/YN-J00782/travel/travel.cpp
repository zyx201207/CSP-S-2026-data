#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	int c1, c2;
	string s1, s2;
	int seat[3] = {};
	char seat1[3] = {};
	cin >> c1 >> s1 >> c2 >> s2;

	for (int j = 0; j <= 2; j++) {
		if (j == 0) {
			seat[1] += 10 * (int)(s1[0] - '0');
		} else if (j == 1) {
			seat[1] += (int)(s1[1] - '0');
		} else {
			seat1[1] = s1[2];
		}
	}
	for (int j = 0; j <= 2; j++) {
		if (j == 0) {
			seat[2] += 10 * (int)(s2[0] - '0');
		} else if (j == 1) {
			seat[2] += (int)(s2[1] - '0');
		} else {
			seat1[2] = s2[2];
		}
	}

	//cout << test[1] << ' ' << test[2] << ' ' << test1[1] << ' ' << test1[2];

	if (c1 == c2) {
		cout << 1;

		if (seat[1] == seat[2]) {
			cout << 1;

			if (seat1[1] <= 'C' && seat1[2] <= 'C') {
				cout << 1;

				if (seat1[1] - seat1[2] == 1 || seat1[1] - seat1[2] == -1) {
					cout << 1;
				} else {
					cout << 0;
					return 0;
				}

			} else if (seat1[1] >= 'D' && seat1[2] >= 'D') {
				cout << 1;

				if (seat1[1] - seat1[2] == 2 || seat1[1] - seat1[2] == -2) {
					cout << 1;
				} else {
					cout << 0;
					return 0;
				}

			} else {
				cout << 0;
				cout << 0;
				return 0;
			}

		} else {
			cout << 0;
			cout << 0;
			cout << 0;
			return 0;
		}

	} else {
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	return 0;
}