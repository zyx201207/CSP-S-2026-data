#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool ge(string a, string b) {
	if ((a == "A" || a == "B" || a == "C") && (b == "D" || b == "E")) {
		return 1;
	}
	return 0;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
	} else {
		cout << 0;
	}
	string a = s1.substr(0, 2);
	string b = s2.substr(0, 2);
	if (a == b && c1 == c2) {
		cout << 1;
	} else {
		cout << 0;
	}
	string c = s1.substr(2, 1);
	string d = s2.substr(2, 1);
	if (ge(c, d) || a != b || c1 != c2) {
		cout << 0;
	} else {
		cout << 1;
	}
	char C = c[0], D = d[0];
	if (abs(C - D) == 1 && !ge(c, d) && a == b && c1 == c2) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}