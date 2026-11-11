#include <bits/stdc++.h>
#define int long long
using namespace std;
int c1, c2;
string s1, s2;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int cnt = 4;

	if (c1 == c2) {
		cout << 1;
		cnt--;

		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << 1;
			cnt--;

			if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') {
				if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') {
					cout << 1;
					cnt--;
				}
			} else {
				if (s1[2] == 'D' || s1[2] == 'F') {
					if (s2[2] == 'D' || s2[2] == 'F') {
						cout << 1;
						cnt--;
					}
				}
			}

			if (cnt == 1) {
				if (s1[2] == 'A' && s2[2] == 'B') {
					cout << 1;
					cnt--;
				} else if (s1[2] == 'B') {
					if (s2[2] == 'A' || s2[2] == 'C') {
						cout << 1;
						cnt--;
					}
				} else if (s1[2] == 'C' && s2[2] == 'B') {
					cout << 1;
					cnt--;
				} else if (s1[2] == 'C' && s2[2] == 'D') {
					cout << 1;
					cnt--;
				} else if (s1[2] == 'D' && s2[2] == 'C') {
					cout << 1;
					cnt--;
				}
			}
		}
	}

	for (int i = 1; i <= cnt; i++) {

		cout << 0;
	}

	return 0;
}