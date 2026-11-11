#include <bits/stdc++.h>
using namespace std;
int x, y;
string s1, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> x >> s1 >> y >> s2;
	if (x == y) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}
	if ((s1[0] - '0') * 10 + (s1[1] - '0') == (s2[0] - '0') * 10 + (s2[1] - '0')) {
		cout << 1;
	} else {
		cout << "000";
		return 0;
	}
	if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C')) {
		cout << 1;
	} else {
		cout << "00";
		return 0;
	}
	if (s1[2] - 'A' + 1 == s2[2] - 'A' || s1[2] - 'A' - 1 == s2[2] - 'A') {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
