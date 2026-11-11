#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 500005;
int n, m, a[MAXN], tot = 0, ans = 0, val[MAXN], vis = 1;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		tot++;
		cin >> a[tot];
		if (a[i] == a[i - 1]) {
			tot--;
			ans++;
		}
	}
	sort(a + 1, a + tot + 1);
	val[1] = 0;
	val[2] = a[2] - a[1];
	for (int i = 3; i <= tot; i++) val[i] = val[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	for (int i = 1; i <= tot; i++) {
		if (val[i] > m) vis = 0;
		if (!vis) {
			ans += i - 1;
			break;	
		}
	}
	cout << ans;
	return 0;
}
