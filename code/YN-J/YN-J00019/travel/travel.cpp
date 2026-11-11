#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		s = s + '1';
	} else {
		s = s + "0000";
		cout << s;
		return 0;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1]) {
		s = s + '1';
	} else {
		s = s + "000";
		cout << s;
		return 0;
	}
	if (s1[2] <= 'C' && s2[2] <= 'C' || s1[2] >= 'D' && s2[2] >= 'D') {
		s = s + '1';
	} else {
		s = s + "00";
		cout << s;
		return 0;
	}
	if (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2])
		s = s + '1';
	else
		s = s + '0';
	cout << s;
	return 0;
}