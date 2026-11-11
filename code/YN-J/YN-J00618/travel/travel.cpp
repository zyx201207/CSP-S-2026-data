#include <bits/stdc++.h>
using namespace std;

bool x(char c1, char c2) {
	if (c1 == 'A' || c1 == 'B' || c1 == 'C') {
		if (c2 == 'A' || c2 == 'B' || c2 == 'C') {
			return true;
		} else {
			return false;
		}
	}
	if (c1 == 'D' || c1 == 'F') {
		if (c2 == 'D' || c2 == 'F') {
			return true;
		} else {
			return false;
		}
	}
	return false;
}

bool w(char c1, char c2) {
	if (c1 == 'A' && c2 == 'B') {
		return true;
	}
	if (c1 == 'B' && (c2 == 'C' || c2 == 'A')) {
		return true;
	}
	if (c1 == 'C' && c2 == 'B') {
		return true;
	}
	if (c1 == 'D' && c2 == 'F') {
		return true;
	}
	if (c1 == 'F' && c2 == 'D') {
		return true;
	}
	return false;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	cout << (int)(c1[1] == c2[1] && c1[0] == c2[0]);
	cout << (int)(c1[1] == c2[1] && c1[0] == c2[0] && s1[0] == s2[0] && s1[1] == s2[1]);
	cout << (int)(c1[1] == c2[1] && c1[0] == c2[0] && s1[0] == s2[0] && s1[1] == s2[1] && x(s1[2], s2[2]));
	cout << (int)(c1[1] == c2[1] && c1[0] == c2[0] && s1[0] == s2[0] && s1[1] == s2[1] && x(s1[2], s2[2])
	              && w(s1[2], s2[2]));
	return 0;
}