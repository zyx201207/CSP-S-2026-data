#include <bits/stdc++.h>
#define MAXN 2000002
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair< int, int > pii;
int n;
ll d;
ll pos[MAXN];
namespace f1t6 {
int mind;
pii dfs(int u, int t, int x) {
	if (u > t || x > mind) return mp(n, 0);
	if (u < t && x == mind) return mp(n, 0);
	if (u == t) return mp(x, 1);
	pii ans = mp(n, 0);
	for (int i = u + 1; i <= t && pos[i] - pos[u] <= d; i++) {
		pii res = dfs(i, t, x + 1);
		mind = min(res.fi, mind);
		if (res.fi < ans.fi) {
			ans.fi = res.fi;
			ans.se = res.se;
		} else if (res.fi == ans.fi) {
			ans.se += res.se;
		}
	}
	return ans;
}
void solve() {
	int ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) 
		cin >> pos[i];
	for (int i = 1; i < n - 1; i++) {
		for (int j = i + 2; j <= n; j++) {
			mind = n;
			pii res = dfs(i, j, 0);
			if (res.second == 2) {
				ans++;
			}
		}
	}
	cout << ans << "\n";
}
}
namespace f11t12 {
void solve() {
	int n;
	ll d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> pos[i];
	}
	if (n <= 3) {
		cout << "0\n";
		return;
	}
	// px + q
	ll p = pos[2] - pos[1];
	d = d / p;
	if (d <= 1) {
		cout << "0\n";
	} else {
		cout << max(0ll, n - d - d + 1) << "\n";
	}
}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		if (c <= 6) f1t6::solve();
		else if (c <= 12) f11t12::solve();
		else f1t6::solve();
	}
	return 0;
}
