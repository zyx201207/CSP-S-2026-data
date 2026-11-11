#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2, s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string s3, s4;
	s3 += s1[0];
	s3 += s1[1];
	s4 += s2[0];
	s4 += s2[1];
	if (c1 == c2) {
		cout << "1";
		if (s3 == s4) {
			cout << "1";
			if (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] <= 'C' && s2[2] >= 'A') {
				cout << "1";
				if (abs(s1[2] - s2[2]) == 1)
					cout << "1";
				else
					cout << "0";
			} else if ((s1[2] == 'D' && s2[2] == 'F') || (s2[2] == 'D' && s1[2] == 'F')) {
				cout << "11";
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}