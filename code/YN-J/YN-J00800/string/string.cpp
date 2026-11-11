#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, a, cnt = 0, cnta = 0;
	cin >> n;
	string s, sa = "";
	for (int i = 1; i <= n; i++) {
		cin >> a >> s;
		for (int j = 1; j <= a; j++) {
			sa += s;
		}
		cnt += a;
	}
	for (int l = cnt / 2 - 1, r = cnt / 2 + (cnt % 2 == 1 ? 1 : 0); r < cnt; l--, r++) {
		if (sa[l] != sa[r])
			cnta++;
	}
	cout << cnta;
	return 0;
}