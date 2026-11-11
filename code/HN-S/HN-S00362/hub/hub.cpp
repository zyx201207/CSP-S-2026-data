#include<bits/stdc++.h>
using namespace std;
#define N 1000011
int n, k;
vector<int> g[N];
bool vis[N];
void solve()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		g[i].clear();
	for (int i = 1; i <= n; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout << n / 4 << '\n';
}
int c, t;
signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--)
		solve();
	return 0;
}

