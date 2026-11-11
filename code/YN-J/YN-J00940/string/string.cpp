#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s = "";

	for (int i = 1; i <= n; i++) {

		long long a;
		char b;
		cin >> a >> b;

		for (int i = 1; i <= a; i++) {

			s += b;
		}
	}

	int ans = 0;
	int l = 0, r = s.size() - 1;

	while (l < r) {
		if (s[l] != s[r])
			ans++;
		l++;
		r--;
	}

	cout << ans;
	return 0;
}