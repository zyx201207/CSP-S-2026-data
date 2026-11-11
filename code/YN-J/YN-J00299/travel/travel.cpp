#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	cin >> c1;
	char s1[5], s2[5];
	for (int i = 1; i <= 3; i++) {
		cin >> s1[i];
	}
	cin >> c2;
	for (int i = 1; i <= 3; i++) {
		cin >> s2[i];
	}
	if (c1 == c2) {
		cout << "1";
	} else {
		cout << "0";
	}
	if (s1[1] == s2[1] && s1[2] == s2[2]) {
		cout << "1";
	} else {
		cout << "0";
	}
	if (s1[1] == s2[1] && s1[2] == s2[2]) {
		if (s1[3] == 'D' && s2[3] == 'F') {
			cout << "1" << "1";
		}

		else if (s1[3] == 'F' && s2[3] == 'D') {
			cout << "1" << "1";
		}

		else if (s1[3] == 'A' && s2[3] == 'B') {
			cout << "1" << "1";
		}

		else if (s1[3] == 'A' && s2[3] == 'C') {
			cout << "1" << "0";
		}

		else if (s1[3] == 'B' && s2[3] == 'A') {
			cout << "1" << "1";
		}

		else if (s1[3] == 'B' && s2[3] == 'C') {
			cout << "1" << "1";
		}

		else if (s1[3] == 'C' && s2[3] == 'B') {
			cout << "1" << "1";
		}

		else if (s1[3] == 'C' && s2[3] == 'A') {
			cout << "1" << "0";
		}
	} else
		cout << "0";
	return 0;
}