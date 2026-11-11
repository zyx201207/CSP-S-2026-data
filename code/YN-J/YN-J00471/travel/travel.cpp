#include <bits/stdc++.h>
using namespace std;

int main() {
	foreopen("travel.in", "r", stdin);
	foreopen("travel.out", "w", stdout);
	string c1, c2, s1, s2, L;
	L = "ABCDF";
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << "1";
	} else {
		cout << "0";
	}
	if (c1 == c2 and s1[0] == s2[0] and s1[1] == s2[1]) {
		cout << "1";
	} else {
		cout << "0";
	}
	if (c1 == c2 and s1[0] == s2[0] and s1[1] == s2[1]) {
		if (s1[2] == L[0] and s2[2] == L[1]) {
			cout << "1";
		}
		if (s1[2] == L[0] and s2[2] == L[2]) {
			cout << "1";
		}
		if (s1[2] == L[1] and s2[2] == L[2]) {
			cout << "1";
		}
		if (s1[2] == L[1] and s2[2] == L[0]) {
			cout << "1";
		}
		if (s1[2] == L[2] and s2[2] == L[0]) {
			cout << "1";
		}
		if (s1[2] == L[2] and s2[2] == L[1]) {
			cout << "1";
		}
		if (s1[2] == L[3] and s2[2] == L[4]) {
			cout << "1";
		}
		if (s1[2] == L[4] and s2[2] == L[3]) {
			cout << "1";
		}
		if (s1[2] == L[0] and s2[2] == L[3]) {
			cout << "0";
		}
		if (s1[2] == L[0] and s2[2] == L[4]) {
			cout << "0";
		}
		if (s1[2] == L[1] and s2[2] == L[3]) {
			cout << "0";
		}
		if (s1[2] == L[1] and s2[2] == L[4]) {
			cout << "0";
		}
		if (s1[2] == L[2] and s2[2] == L[3]) {
			cout << "0";
		}
		if (s1[2] == L[2] and s2[2] == L[4]) {
			cout << "0";
		}
		if (s1[2] == L[3] and s2[2] == L[0]) {
			cout << "0";
		}
		if (s1[2] == L[4] and s2[2] == L[0]) {
			cout << "0";
		}
		if (s1[2] == L[3] and s2[2] == L[1]) {
			cout << "0";
		}
		if (s1[2] == L[4] and s2[2] == L[1]) {
			cout << "0";
		}
		if (s1[2] == L[3] and s2[2] == L[2]) {
			cout << "0";
		}
		if (s1[2] == L[4] and s2[2] == L[2]) {
			cout << "0";
		}
	}
	if (c1 == c2 and s1[0] == s2[0] and s1[1] == s2[1] and s1[2] == L[3] and s2[2] == L[4]) {
		cout << "1";

	} else {
		cout << "0";
	}
	if (c1 == c2 and s1[0] == s2[0] and s1[1] == s2[1] and s1[2] == L[4] and s2[2] == L[3]) {
		cout << "1";

	} else {
		cout << "0";
	}
	return 0;
}