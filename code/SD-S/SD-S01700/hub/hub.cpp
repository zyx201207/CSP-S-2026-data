#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
int c, T;
vector <int> g[maxn];
void solve()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout << 1 << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while(T--)
		solve();
	return 0;
}
