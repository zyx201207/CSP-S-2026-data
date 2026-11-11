#include <bits/stdc++.h>
#include <cstdio>
#include <iomanip>
using namespace std;
string s1[105];
string s2[105];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2, z, x, temp, s, w, y, t, c, d, e, f, g;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
	}
	if (c1 == c2) {
		c = '1';
	}
	for (int i = 0; i <= 3; i++) {
		temp = s1[0], s = s1[1], t = s1[2];
	}
	for (int i = 0; i <= 3; i++) {
		w = s2[0], y = s2[1];
		z = s2[2];
	}
	if (temp == w && s == y) {
		d = "1";
	}
	if (temp != w && s != y) {
		d = '0';
	}


	if ((t == "A" && z == "B") || (t == "B" && z == "A") || (t == "A" && z == "C") || (t == "B" && z == "C") || (t == "C"
	        && z == "B") || (t == "C"
	                         && z == "A") || (t == "F" && z == "D") || (t == "D" && z == "F")) {
		e = "1";
	}
	if ((t != "A" && z != "B") || (t == "B" && z == "A") || (t != "A" && z != "C") || (t != "B" && z != "C") || (t != "C"
	        && z != "B") || (t != "C" && z != "A") || (t != "F" && z != "D") || (t != "D" && z != "F")) {
		e = "0";
	}
	if ((t == "A" && z == "C") || (t == "C" && z == "A") || (t == "A" && z == "D") || (t == "D" && z == "A") || (t == "A"
	        && z == "F") || (t == "B" && z == "D") || (t == "B" && z == "F") || (t == "D" && z == "B") || (t == "F" && z == "B")
	        || (t == "C" && z == "D") || (t == "C" && z == "F") || (t == "D" && z == "C") || (t == "F" && z == "C")) {
		g = "0";
	}
	if ((t != "A" && z != "C") || (t != "C" && z != "A") || (t != "A" && z != "D") || (t != "D" && z != "A")
	        || (t != "A" && z != "F") || (t != "B" && z != "D") || (t != "B" && z != "F") || (t != "D" && z != "B") || (t != "F"
	                && z != "B") || (t != "C" && z != "D") || (t != "C" && z != "F") || (t != "D" && z != "C") || (t != "F" && z != "C")) {
		g = "1";
	}
	cout << c << d << e << g;

}
