#include <bits/stdc++.h>
using namespace std;
int a1, a2;
string s1, s2;
int cnt;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> a1 >> s1 >> a2 >> s2;
	if (a1 == a2) {
		cout << 1;
		cnt++;
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << 1;
			cnt++;
			if ((s1[2] - 'A') / 4 == (s2[2] - 'A') / 4) {
				cout << 1;
				cnt++;
				if (abs((s1[2] - 'A') - (s2[2] - 'A')) == 1) {
					cout << 1;
					cnt++;
				}
			}
		}
	}
	for (int i = 1; i <= 4 - cnt; i++) {
		cout << "0";
	}
	return 0;
}