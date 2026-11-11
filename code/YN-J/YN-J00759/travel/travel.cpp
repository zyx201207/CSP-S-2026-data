#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int zd = 0;
	int cs = 0;
	if (s1 != s2) {
		if (cs == 0) {
			if (c1 == c2) {
				cout << 1;
			} else {
				cout << 0;
				cs++;
			}
		} else {
			cout << 0;
		}
		for (int i = 0; i <= s1.size() - 1; i++) {
			if (cs == 0) {
				if (s1[i] - '0' >= 0 && s1[i] - '0' <= 9 && s2[i] - '0' >= 0 && s2[i] - '0' <= 9) {
					if (s1[i] - '0' != s2[i] - '0') {
						cout << 0;
						zd += 1;
						cs++;
						break;
					}
				}
			} else {
				cout << 0;
				cs++;
			}
		}
		if (zd == 0) {
			cout << 1;
		}
		if (cs == 0) {
			if ((s1[s1.size() - 1] == 'A' || s1[s1.size() - 1] == 'B' || s1[s1.size() - 1] == 'C') && (s2[s2.size() - 1] == 'D'
			        || s2[s2.size() - 1] == 'F') || (s2[s2.size() - 1] == 'A' || s2[s2.size() - 1] == 'B' || s2[s2.size() - 1] == 'C')
			        && (s1[s1.size() - 1] == 'D' || s1[s1.size() - 1] == 'F')) {
				cout << 0;
				cs++;
			} else {
				cout << 1;
			}
		} else {
			cout << 0;
			cs++;
		}
		if (cs == 0) {
			if (abs(s1[s1.size() - 1] - s2[s2.size() - 1]) == 1) {
				cout << 1;
			} else {
				cout << 0;
			}
		} else {
			cout << 0;
		}
	} else {
		string ans = "0000";
		cout << ans;
	}
	return 0;
}