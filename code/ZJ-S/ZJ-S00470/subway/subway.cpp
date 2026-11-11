//∑÷≤„Õºº”Dij 
#include<bits/stdc++.h>
using namespace std;
#define int long long
using PII = pair<int, int>;
const int N = 1e3 + 10;
struct edge{
	int pos, now1, now2;
};
struct node{
	int a, t;
	int cur;
};
int c, n, m, d, q;
int w[N];
int dis[N][N];
vector<vector<node>> qwe;
vector<PII> G[N];
vector<edge> group[N];
void Dij(int s)
{
	memset(dis[s], 0x3f, sizeof dis[s]);
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.emplace(dis[s][0] = 0, 0);
	while(!pq.empty())
	{
		int d = pq.top().first, u = pq.top().second; pq.pop();
		if(d > dis[s][u]) continue;
		for (auto to : G[u])
		{
			int v = to.first, w = to.second;
			if(dis[s][v] > dis[s][u] + w)
			{
				dis[s][v] = dis[s][u] + w;
				pq.emplace(dis[s][v], v);
			}
		} 
	}
}
signed main()
{
	cin.tie(0), cout.tie(0) -> sync_with_stdio(false);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	int mm = m;
	for (int i = 1; i <= m; i++)  cin >> w[i];
	qwe.resize(m + 1);
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		qwe[i].resize(k + 1);
		for (int j = 1; j <= k; j++)
		{
			cin >> qwe[i][j].a >> qwe[i][j].t;
			qwe[i][j].cur = i;
			if(i == 1) {
				group[qwe[i][j].a].push_back({qwe[i][j].a, i, j}); 
				if(j != 1) {
					G[qwe[i][j].a].push_back({qwe[i][j - 1].a, 0});
					G[qwe[i][j - 1].a].push_back({qwe[i][j].a, 0});
				}
			}
			if(i != 1)
			{
				if(group[qwe[i][j].a].size())
				{
					int pos = qwe[i][j].a;
					qwe[i][j].a = ++m;
					group[pos].push_back({qwe[i][j].a, i, j});
					if(j != 1){
						G[qwe[i][j - 1].a].push_back({qwe[i][j].a, 0});
						G[qwe[i][j].a].push_back({qwe[i][j - 1].a, 0});
					}
				}else{
					group[qwe[i][j].a].push_back({qwe[i][j].a, i, j});
					if(j != 1)
					{
						G[qwe[i][j - 1].a].push_back({qwe[i][j].a, 0});
						G[qwe[i][j].a].push_back({qwe[i][j - 1].a, 0});
					}
				}
			}
		}
	}
	for (int k = 1; k <= mm; k++)
	{
		for (int i = 0; i < group[k].size(); i++)
		{
			for (int j = i + 1; j < group[k].size(); j++)
			{
				G[group[k][i].pos].push_back(make_pair(group[k][j].pos, 
				qwe[group[k][i].now1][group[k][i].now2].t + qwe[group[k][j].now2][group[k][j].now2].t));
				G[group[k][j].pos].push_back(make_pair(group[k][i].pos, 
				qwe[group[k][i].now1][group[k][i].now2].t + qwe[group[k][j].now2][group[k][j].now2].t));
			}	
		}	
	}
	for (int i = 1; i <= m; i++)
	{
		for (auto v : group[i]) G[0].push_back({v.pos, qwe[v.now1][v.now2].t});
		Dij(i);
		G[0].clear();
	}
//	for (int i = 1; i <= m; i++)
//	{
//		cout << i << '\n';
//		for (auto v : G[i]) cout << v.first << " ";
//		cout << '\n';
//	}
//	for (int i = 1; i <= m; i++) for (int j = 1; j <= m; j++) cout << dis[i][j] << " \n"[j == m];
	while(q--){
		int l, r;
		cin >> l >> r;
		int ans = 1e15;
		for (auto to : group[l]) ans = min(ans, dis[to.pos][r]);
		cout << ans + w[l] + w[r] << '\n';
	}
	return 0;	
} 
