#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int M = 502, N = 5e5+2;
int c, n, m, d, q;
int w[M], k[M], t[N][M];


priority_queue<int, vector<int>, greater<int> > Q;
int S, E, fa[M];
long long dis[M], ans;
vector<int> g[M];
bool vis[M];

void dij()
{
	memset(dis, 0x3f, sizeof dis);
	memset(vis, false, sizeof vis);
	while(!Q.empty())Q.pop();
	vis[S] = true;
	dis[S] = 0;
	Q.push(S);
	while(!Q.empty())
	{
		int u = Q.top();
		Q.pop();
		for (auto v : g[u]) 
		{		
			if (v != fa[u] && !vis[v])
			{
				if (dis[u] + t[u][v] < dis[v])
				{
					
					dis[v] = dis[u] + t[u][v];
					fa[v] = u;
					Q.push(v);
				}
			}
		}
	}
}
void final_calc(int lst)
{
	ans += t[lst][lst];
	if (lst == S)
	{
		return;
	}
	final_calc(fa[lst]);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	} 
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			int v; cin>>v;
			g[i].push_back(v);
			cin >> t[i][v];
		}
	}
	while (q--)
	{
		cin >> S >> E;
		dij();
		ans = dis[E];
		final_calc(fa[E]);
		cout << ans + w[S] + w[E] << '\n';
	}
	cout.flush();
	return 0;
} 
