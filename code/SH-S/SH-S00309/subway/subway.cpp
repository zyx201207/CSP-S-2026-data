#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define int long long
using namespace std;
int c, n, m, D, q, w[500005], dis[505][505];
struct node
{
	short to;
	int w;
};
vector <node> G[500005], G2[505];
int query(int s, int t)
{
	int ans = 0x3f3f3f3f3f3f3f3f;
	for(int i = 0; i < G[s].size(); i++)
		for(int j = 0; j < G[t].size(); j++)
			ans = min(ans, G[s][i].w + dis[G[s][i].to][G[t][j].to]+G[t][j].w);
	return ans+w[s]+w[t];
//	return ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> D >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	int k, a, t;
	for(int i = 1; i <= n; i++)
	{
		cin >> k;
		while(k--)
		{
			cin >> a >> t;
			G[a].push_back({i,t});
		}
	}
	memset(dis, 63, sizeof dis);
	for(int i = 1; i <= n; i++) dis[i][i] = 0; 
	for(int i = 1; i <= m; i++)
		for(int j1 = 0; j1 < G[i].size(); j1++)
			for(int j2 = j1+1; j2 < G[i].size(); j2++)
				dis[G[i][j1].to][G[i][j2].to] = dis[G[i][j2].to][G[i][j1].to] = min(dis[G[i][j1].to][G[i][j2].to],G[i][j1].w+G[i][j2].w);
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k]+dis[k][j]);
	while(q--)
	{
		int s, t;
		cin >> s >> t;
		cout << query(s, t) << "\n";
	}
} 
