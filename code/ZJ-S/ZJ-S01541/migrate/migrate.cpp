#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n, d;
	cin >> n >> d;
	vector <long long> x(n + 5);
	bool vis[n + 5];
	
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (x[i] - x[i - 1] > d && x[i] - x[i + 1] > d) vis[i] = false;
		else sum++;
	}
	if (sum == 0) {
		cout << 0 << '\n';
		return ;
	}
	int cnt = 1;
	int ans = 0;
	for (int u = 1, v = u + 1; u <= n && v <= n; u++, v++) {
		if (!vis[u] || !vis[v]) continue;
	}
	cout << cnt << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--) 
		solve();
	return 0;
}
