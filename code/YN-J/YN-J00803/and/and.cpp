#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
ll n, m, maxn = 0;

void dfs(ll dep, ll cnt, ll sum) {
	if (cnt == m) {
		maxn = max(maxn, sum);
	}
	if (dep > n || n - dep + 1 + cnt < m) {
		return;
	}
	dfs(dep + 1, cnt, sum);
	dfs(dep + 1, cnt + 1, sum & a[dep]);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 0, 2147483647);
	cout << maxn;
	return 0;
}