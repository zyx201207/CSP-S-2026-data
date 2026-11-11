#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] == c1[0] and c1[1] == c2[1]) {
		cout << 1;
		if (s1[0] == s2[0] and s1[1] == s2[1]) {
			cout << 1;
			//the third and fourth step
			if (s1[2] == 'D' and s2[2] == 'F') {
				cout << 11;
			} else if (s1[2] == 'A' and s2[2] == 'B') {
				cout << 11;
			} else if (s1[2] == 'A' and s2[2] == 'C') {
				cout << 10;
			} else if (s1[2] == 'B' and s2[2] == 'A') {
				cout << 11;
			} else if (s1[2] == 'B' and s2[2] == 'C') {
				cout << 11;
			} else if (s1[2] == 'C' and s2[2] == 'A') {
				cout << 10;
			} else if (s1[2] == 'C' and s2[2] == 'B') {
				cout << 11;
			} else if (s1[2] == 'F' and s2[2] == 'D') {
				cout << 11;
			} else {
				cout << "00";
				return 0;
			}
		} else {
			cout << "000";
			return 0;
		}
	} else
		cout << "0000";
	return 0;
}