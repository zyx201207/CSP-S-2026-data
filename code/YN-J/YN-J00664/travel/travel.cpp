#include <bits/stdc++.h>
using namespace std;
c1[2], s1[3], c2[2], s2[3];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	for (int i = 0; i < 2; i++) {
		cin >> c1[i];
	}
	for (int i = 0; i < 3; i++) {
		cin >> s1[i];
	}
	for (int i = 0; i < 2; i++) {
		cin >> c2[i];
	}
	for (int i = 0; i < 3; i++) {
		cin >> s2[i];
	}
	if (c1[0] == c2[0] && c1[1] == c2[1]) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << 1;
	} else {
		cout << 0;
	}

	if ('A' <= s1[2] && s1[2] <= 'C') {
		if ('A' <= s2[2] && s2[2] <= 'C') {
			cout << 1;
			if (s1[2] - s2[2] - 'A' == 1 || s2[2] - s1[1] - 'A' == 1) {
				cout << 1;
			} else
				cout << 0;
		} else
			cout << 0;
	} else if ('D' <= s1[2] && s1[2] <= 'F') {
		if ('D' <= s2[2] && s2[2] <= 'F') {
			cout << 1;
			if (s1[2] - s2[2] - 'A' == 1 || s2[2] - s1[1] - 'A' == 1) {
				cout << 1;
			} else
				cout << 0;
		} else
			cout << 0;
	}


	return 0;
}