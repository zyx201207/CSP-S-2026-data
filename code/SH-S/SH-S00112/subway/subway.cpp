#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, long long>;

const int N = 500 + 9;
const int M = 5e5 + 9;
const long long INF = 1e18 + 7;
long long w[M], dis[N][N];
vector<pii> connect[M];
int c, n, m, d, q;
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
		cin >> w[i];
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			dis[i][j] = INF;
	for(int i = 1;i <= n;i++)
		dis[i][i] = 0;
	for(int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		while(k--)
		{
			int u, w;
			cin >> u >> w;
			connect[u].push_back(make_pair(i, w));
		}
	}
	//最初的所有线路之间的最短距离 
	for(int node = 1;node <= m;node++)
	{
		for(int i = 0;i <= connect[node].size() - 1;i++)
			for(int j = i + 1;j <= connect[node].size() - 1;j++)
			{
				int u = connect[node][i].first;
				long long d1 = connect[node][i].second;
				int v = connect[node][j].first;
				long long d2 = connect[node][j].second;
				dis[u][v] = min(dis[u][v], d1 + d2);
				dis[v][u] = min(dis[v][u], d1 + d2);
			}
	}
	//floyed最短路
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			for(int k = 1;k <= n;k++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	//回答询问 
	while(q--)
	{
		int u, v;
		long long ans = INF;
		cin >> u >> v;
		for(pii p1 : connect[u])
			for(pii p2 : connect[v])
			{
				int node1 = p1.first, d1 = p1.second;
				int node2 = p2.first, d2 = p2.second;
				ans = min(ans, dis[node1][node2] + d1 + d2 + w[u] + w[v]);
			}
		cout << ans << '\n';
	}
	
	return 0;
}
