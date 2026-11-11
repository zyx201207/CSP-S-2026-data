#include<bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << 1;
			char p = s1[2], q = s2[2];
			if ((p >= 'A' && p <= 'C' && q >= 'A' && q <= 'C') || (p >= 'D' && p <= 'F' && q >= 'D' && q <= 'F')) {
				cout << 1;
				if ((p=='A' && q=='B') || (p=='B' && q=='A') || (p=='B' && q=='C') || (p=='C' && q=='B') || (p=='D' && q=='F') || (p=='F' && q=='D')) {
					cout << 1;
				}
				else {
					cout << "0\n";
					return 0;
				}
			}
			else {
				cout << "00\n";
				return 0;
			}
		}
		else {
			cout << "000\n";
			return 0;
		}
	}
	else {
		cout << "0000\n";
		return 0;
	}
	return 0;
}
