#include <bits/stdc++.h>
using namespace std;
char c, s;
int r, u, x, y;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> r >> u >> c >> x >> y >> s ;

	if (r == x) {
		cout << "1";
	} else {
		cout << "0";
	}

	if (u == y) {
		cout << "1";
	} else {
		cout << "0";
	}

	if (u == y && c != 'D' && c != 'F' && s != 'D' && s != 'F' || u == y && c != 'A' && c != 'B' && c != 'C' && s != 'A'
	        && s != 'B' && s != 'C') {
		cout << "1";
	} else {
		cout << "0";
	}

	if (u == y && c - s == -1 || u == y && s - c == -1) {
		cout << "1";
	} else {
		cout << "0";
	}

	return 0;
}
