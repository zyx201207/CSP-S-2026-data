#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen(travel.in,"r",std.in)
	freopen(travel.out,"w",std.out)
	int c1, s1, c2, s2;
	string s;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		s += '1';
	}
	if (s1 == s2) {
		s += '1';
	}
	if (s1 == s2) {
		s += '1';
	}
	if (s1 + 1 == s2 || s1 - 1 == s2) {
		s += '1';
	}
	cout << s;
	return 0;
}