#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[200005];
ll ans = -1;
ll n, m;

void dfs(ll sum, ll id, ll cnt) {
	if (cnt == m) {
		ans = max(ans, sum);
		return;
	}
	if (id == n + 1) {
		return;
	}

	dfs(sum, id + 1, cnt);
	if (cnt == 0) {
		dfs(a[id], id + 1, cnt + 1);
	} else {
		dfs(sum & a[id], id + 1, cnt + 1);
	}

}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 1, 0);
	cout << ans << "\n";
	return 0;
}