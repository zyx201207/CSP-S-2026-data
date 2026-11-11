#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e6 + 5;
int c, t, n, d, x[MAXN];
bool check(int l, int r) {
	map<int, bool> mp;
	int cnt = 0;
	for(int i = l + 1; i <= n; i++) if(x[i] <= x[l] + d) mp[i] = 1; else break;
	for(int i = r - 1; i; i--) if(x[i] >= x[r] - d) if(mp[i]) cnt++; else; else break;
	return cnt == 2;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> t;
	while(t--) {
		int ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		for(int i = 1; i <= n; i++) {
			int l = min<int>(n, upper_bound(x + i, x + n + 1, x[i] + d) - x);
			int r = min<int>(n, lower_bound(x + l, x + n + 1, x[l] + d) - x);
			for(int j = l; j <= r; j++) if(check(i, j)) ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
