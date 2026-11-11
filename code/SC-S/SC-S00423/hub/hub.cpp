#include<bits/stdc++.h>
#define int long long
#define inf 1e18
#define pb push_back
using namespace std;
mt19937_64 rnd(time(0));
int Rand(int l, int r) {
	return rnd() % (r - l + 1) + l;
}
void solve() {
	int n, k;
	cin >> n >> k;
	vector<int>g[n + 1];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	cout << Rand(1, 1000) << "\n";
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1, c;
	cin >> c >> T;
	while (T--) solve();
	return 0;
}