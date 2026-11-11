#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool t(char c, char q) {
	if (c == 'D' && q == 'C' || c == 'C' && q == 'D') {
		return false;
	} else {
		return true;
	}
}

bool op(string v, string z) {
	if (v[0] == z[0] && v[1] == z[1]) {
		char l, i;
		l = v[2], i = z[2];
		if (abs(l - i) == 1 && t(l, i)) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

bool check(string j, string m) {
	if (j[2] == 'A' || j[2] == 'B' || j[2] == 'C') {
		if (m[2] == 'A' || m[2] == 'B' || m[2] == 'C') {
			return true;
		} else {
			return false;
		}
	} else {
		if (m[2] == 'D' || m[2] == 'F') {
			return true;
		} else {
			return false;
		}
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string b, d;
	int a, c;
	cin >> a >> b >> c >> d;
	if (a == c)
		cout << 1;
	else
		cout << 0;
	if (b[0] == d[0] && b[1] == d[1] && a == c) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (b[0] == d[0] && b[1] == d[1] && check(b, d) && a == c) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (op(b, d) && a == c)
		cout << 1;
	else
		cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}