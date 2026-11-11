#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
string ans;

inline bool istongce (char x, char y) {
	if (x + y == 'D' + 'F') {
		return true;
	} else if (x == 'A' && (y == 'B' || y == 'C') || x == 'B' && (y == 'A' || y == 'C') || x == 'C' && (y == 'A'
	           || y == 'B')) {
		return true;
	}
	return false;
}

inline bool ispangbian (char x, char y) {
	if (x == 'A' && y == 'B' || x == 'B' && (y == 'A' || y == 'C') || x == 'C' && y == 'B' || x == 'D' && y == 'F'
	        || x == 'F' && y == 'D') {
		return true;
	}
	return false;
}

int main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
		return 0;
	}
	string x = s1.substr (0, 2);
	string y = s2.substr (0, 2);
	if (x != y) {
		cout << "1000";
		return 0;
	}
	char xx = s1[2], yy = s2[2];
	if (!istongce (xx, yy)) {
		cout << "1100";
		return 0;
	}
	if (!ispangbian (xx, yy)) {
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
}