#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c, s, cc, ss;
	int flag = 1, fflag = 1, ffflag = 1;
	cin >> c >> s >> cc >> ss;
	if (c == cc) {
		cout << 1;
	} else {
		flag = 0;
		cout << 0;
	}
	for (int i = 0; i <= 1; i++) {
		if (s[i] != ss[i]) {
			fflag = 0;
			break;
		}
	}
	if (fflag && flag)
		cout << 1;
	else
		cout << 0;
	if (!flag || !fflag)
		cout << 0;
	else {
		if (s[2] <= 'C' && s[2] >= 'A') {
			if (ss[2] < 'A' || ss[2] > 'C') {
				ffflag = 0;
				cout << 0;
			} else {
				cout << 1;
			}
		}
		if (s[2] <= 'F' && s[2] >= 'D') {
			if (ss[2] < 'D' || ss[2] > 'F') {
				ffflag = 0;
				cout << 0;
			} else
				cout << 1;
		}
	}
	if (flag && fflag && ffflag && abs(s[2] - ss[2]) == 1) {
		cout << 1;
	} else
		cout << 0;
	return 0;
}