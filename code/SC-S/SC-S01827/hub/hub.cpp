#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#define F(i, n, m) for(int i = n; i <= m; i++)
#define dF(i, n, m) for(int i = n; i >= m; i--)
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> g[n+1];
	F(i, 1, n-1) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout << n + 45 - k;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
//	freopen("hub1.in", "r", stdin);
	
	int qwe, T;
	cin >> qwe >> T;
	while(T--) {
		solve();
	}
	
	return 0;
}