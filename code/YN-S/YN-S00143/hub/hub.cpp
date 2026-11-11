#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
int n, k;
vector<int>p[maxn];

ll upz(ll x, ll y) {
	if (x / y * y == x)
		return x / y;
	else
		return x / y + 1;
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	ll t = upz((n - k) / 2, 2);
	ll p = upz(n - k - t, 2);
	ll ans = max(t, p);
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}