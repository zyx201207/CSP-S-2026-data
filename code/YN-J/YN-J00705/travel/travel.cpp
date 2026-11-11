#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string ans = "0000";
	int cr = 0, cx = 0;
	for (int i = 0; i < 2; i++) {
		cr *= 10;
		cr += c1[i] - '0';
		cx *= 10;
		cx += c2[i] - '0';
	}
	if (cr == cx) {
		ans[0] = '1';
		int zr = 0, zx = 0;
		for (int i = 0; i < 2; i++) {
			zr *= 10;
			zr += s1[i] - '0';
			zx *= 10;
			zx += s2[i] - '0';
		}
		if (zr == zx) {
			ans[1] = '1';
			if (s1[2] <= 'C' && s2[2] <= 'C' || s1[2] >= 'D' && s2[2] >= 'D') {
				ans[2] = '1';
				if (abs((int)s1[2] - (int)s2[2]) == 1) {
					ans[3] = '1';
					cout << ans;
				} else {
					cout << ans;
				}
			} else {
				cout << ans;
			}
		} else {
			cout << ans;
		}
	} else {
		cout << ans;
	}
	return 0;
}