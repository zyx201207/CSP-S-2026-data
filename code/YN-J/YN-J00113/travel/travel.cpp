#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen(" travel.in", "r", stdin);
	freopen(" travel.out", "w", stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	string s = " ";
	if (a == c) {
		s += '1';
	} else
		s += '0';
	if (b[0] == d[0] && b[1] == d[1]) {
		s += '1';
	} else {
		s += '0';
	}
	if (b[2] >= 'D' && b[2] <= 'F' && d[2] >= 'D' && d[2] <= 'F' || b[2] >= 'A' && b[2] <= 'C' && d[2] >= 'A'
	        && d[2] <= 'C' && s[1] == '1') {
		s += '1';
	} else {
		s += '0';
	}

	if (abs(b[2] - d[2]) == 1 && s[2] == '1') {
		s += '1';
	} else {
		s += '0';
	}
	cout << s;

	return 0;
}
