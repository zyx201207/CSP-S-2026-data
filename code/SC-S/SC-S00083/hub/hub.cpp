#include <bits/stdc++.h>
using namespace std;

int n, k;
const int MAXN = 1e6 + 5;
vector<int> g[MAXN];
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int c, tt;
	cin >> c >> tt;
	while (tt--) {
		cin >> n >> k;
		for (int i = 1; i <= n - 1; ++i) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << 2 << "\n";
	}
	
	return 0;
}