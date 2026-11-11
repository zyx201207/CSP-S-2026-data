#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s = {""};
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int cnt;
		char op;
		cin >> cnt >> op;
		for (int j = 1; j <= cnt; j++)
			s += op;
	}
	int len = s.size();
	int len2 = len;
	if (len % 2 == 1)
		len = (len + 1) / 2;
	else
		len /= 2;
	for (int i = 0; i < len; i++)
		if (s[i] != s[len2 - 1 - i])
			ans++;
	cout << ans;
	return 0;
}