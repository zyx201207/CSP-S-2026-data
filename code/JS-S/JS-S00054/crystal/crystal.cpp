#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 500010;

int n, m, a[N], s[N], pw[25];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	pw[0] = 1;
	for(int i = 1; i <= 20; i++)
		pw[i] = pw[i - 1] * 2;
	for(int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	int ans = -1;
	for(int i = 1; i <= n; i++) {
		int l = 0;
		for(int j = 20; j >= 0; j--) {
			int nl = l + pw[j];
			if(nl > i)
				continue ;
			if(a[i] * (i - nl + 1) - (s[i] - s[nl - 1]) > m)
				l = nl;
		}
		ans = max(ans, i - l);
	}
	cout << ans << '\n';
	return 0;
}