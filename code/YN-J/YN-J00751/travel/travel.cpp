#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string ans = "";
	if (c1 != c2) {
		cout << "0000";
		return 0;
	} else {
		ans += '1';
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			ans += "1";
			if ((s1[2] == 'D' || s1[2] == 'F')
			        && (s2[2] == 'D' || s2[2] == 'F')
			        || (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')
			        && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) {
				ans += "1";
				if (char(s1[2] + 1) == s2[2] || char(s1[2] - 1) == s2[2]) {
					ans += "1";
				}
			}
		}
	}
	for (int i = 0; i <= 3; i++) {
		cout << (ans[i] != '1' ? "0" : "1");
	}




	return 0;
}
/*
02 01A 02 01B
02 01C 02 01A
02 01C 02 01D
02 02B 02 01A
02 01A 03 01A


*/