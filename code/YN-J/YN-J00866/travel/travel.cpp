#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	string s1, s2;
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> s1 >> b >> s2;
	if (a == b) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}
	if ((s1[0] + s1[1] == s2[0] + s2[1])) {
		cout << 1;
	} else {
		cout << "000";
		return 0;
	}
	if ((s1[2] - 'A' <= 2 && s2[2] - 'A' <= 2) || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')) {
		cout << 1;
	} else {
		cout << "00";
		return 0;
	}
	if ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D') || abs(s2[2] - s1[2]) <= 1) {
		cout << 1;
	} else
		cout << 0;
	return 0;
}