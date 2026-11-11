#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	string s;
	for (int i = 1; i <= n; i++) {
		int ai;
		char ci;
		cin >> ai >> ci;
		while (ai--) {
			s += ci;
		}
	}
	int ans = 0;
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - 1 - i]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
