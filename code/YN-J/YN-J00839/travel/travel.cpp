#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == c2) {
		cout << 1;
	} else {
		cout << 0;
	}

	if (s1[1] == s2[1]) {
		cout << 1;
	} else {
		cout << 0;
	}

	if (s1[2] == 'A' && s2[2] == 'A') {
		cout << 1;
	} else {
		if (s1[2] == 'B' && s2[2] == 'B') {
			cout << 1;
		} else {
			if (s1[2] == 'C' && s2[2] == 'C') {
				cout << 0;
			} else {
				cout << 1;
			}
		}
	}


	if (s1[2] == 'A' && s2[2] == 'A' + 1) {
		cout << 1;
	} else {
		if (s1[2] == 'B' && s2[2] == 'B' + 1) {
			cout << 1;
		} else {
			cout << 0;
		}
	}


	return 0;
}
