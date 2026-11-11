#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int t, n, cnt = 0, x = 0;
	char c;
	string s;
	cin >> t;
	if (t == 1) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= t; i++) {
		cin >> n >> c;
		for (int j = 1; j <= n; j++) {
			s += c;
		}
	}
	if (s.size() % 2 == 0) {
		x = 1;
	}
	for (int i = 0; i <= s.size() / 2 - x; i++) {
		if (s[i] != s[(s.size() - 1) - i]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
