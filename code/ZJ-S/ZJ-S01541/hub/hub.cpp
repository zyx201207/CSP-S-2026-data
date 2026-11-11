#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n, k;
	cin >> n >> k;
	vector <int> a;
	int Max = 0;
	int Min = 1e9;
	for (int i = 1; i <= n; i++) {
		int u, v;
		cin >> u >> v;
		a[u] = v;
		a[v] = u;
		Max = max (Max, max(u, v));
		Min = min (Min, min(u, v));
	}
	cout << Max - Min << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--) {
		solve();
	}
	return 0;
}
