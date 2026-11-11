#include <bits/stdc++.h>

using namespace std;

int c1, c2;
string s1, s2;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 == c2) {
		cout << "1";
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << "1";
			char q = s1[2], p = s2[2];
			if (q == 'A' || q == 'B' || q == 'C') {
				if (p == 'A' || p == 'B' || p == 'C') {
					cout << "1";
					if (q == 'A' && p == 'B' || q == 'B' && q == 'A' || q == 'B' && q == 'C' || q == 'C' && q == 'B') {
						cout << "1";
					} else {
						cout << "0";
					}
				} else {
					cout << "00";
				}
			} else {
				if (p == 'D' || p == 'F') {
					cout << "11";
				} else {
					cout << "00";
				}
			}
		} else {
			cout << "000"; 
		}
	} else {
		cout << "0000";
	}
	
	return 0;
}
