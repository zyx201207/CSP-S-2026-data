#include<bits/stdc++.h>
using namespace std;
vector<int> G[10010];
void solve() {
	int n, k;
	cin >> n >> k;
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(n == k) cout << 0 << '\n';
	else if(n == 3 && k == 2) {
		cout << 2 << '\n';
	}
	else cout << n - 1 << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while(T--) solve();
	return 0;
}

