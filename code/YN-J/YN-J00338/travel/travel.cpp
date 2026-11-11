#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("treval.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << "1";
	} else
		cout << "0";
	int wei1 = s1[0] - '0' + s1[1] - '0';
	int wei2 = s2[0] - '0' + s2[1] - '0';
	if (c1 == c2 && wei1 == wei2) {
		cout << "1";
	} else
		cout << "0";
	if (c1 == c2 && wei1 == wei2 && (s1[2] < 'D' && s2[2] < 'D' || s1[2] >= 'D' && s2[2] >= 'D')) {
		cout << "1";
		if (abs(wei1 - wei2) == 1 && s1[2] == s2[2] || wei1 == wei2 && abs(s1[2] - s2[2]) == 1) {
			cout << '1';
		}
	} else
		cout << "00";
	return 0;
}