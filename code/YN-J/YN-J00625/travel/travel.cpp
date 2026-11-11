#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2, s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << 1;
	} else {
		cout << "000";
		return 0;
	}
	char ch1 = s1[2], ch2 = s2[2];
	if (((ch1 == 'A' || ch1 == 'B' || ch1 == 'C') && (ch2 == 'A' || ch2 == 'B' || ch2 == 'C')) || ((ch1 == 'D'
	        || ch1 == 'F') && (ch2 == 'D' || ch2 == 'F'))) {
		cout << 1;
	} else {
		cout << "00";
		return 0;
	}
	if (ch1 > ch2)
		swap(ch1, ch2);
	if (((ch1 == 'A') && (ch2 == 'B')) || ((ch1 == 'B') && (ch2 == 'C')) || ((ch1 == 'D') && (ch2 == 'F'))) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}