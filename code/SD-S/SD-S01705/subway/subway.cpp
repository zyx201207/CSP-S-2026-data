#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 500005, N = 505;
struct node
{
	int sta, id, co;//所在层号，在该层的位置，t[sta][id] 
};
vector <node> spot[M];
int c, n, m, d, q, k[N], we[M], stsm[M];
vector <int> a[N], t[N];
int pre[N];//前i层点数和 
	struct edge
	{
		int v, w;
	};
	vector <edge> e[M];

struct node2
{
	int u, dis;
};
bool operator> (const node2& a, const node2& b) { return a.dis > b.dis; }
int dis[M];
bool vis[M];
void dijkstra(int s)
{
	for(int i = 1 ; i <= pre[n] ; i ++)
	{
		vis[i] = 0;
		dis[i] = 1e18;
	}
	priority_queue <node2, vector<node2>, greater<node2> > qu;
	qu.push({s, 0});
	dis[s] = 0;
	while(!qu.empty())
	{
		node2 t = qu.top();
		qu.pop();
		int u = t.u;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0 ; i < e[u].size() ; i ++)
		{
			int v = e[u][i].v, w = e[u][i].w;
			if(dis[v] > dis[u] + w)
			{
				qu.push({v, dis[u] + w});
				dis[v] = dis[u] + w;
			}
		}
	}
}

void solve()
{
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i ++) cin >> we[i];
	
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> k[i];
		for(int j = 1 ; j <= k[i] ; j ++)
		{
			int aa, tt;
			cin >> aa >> tt;
			stsm[aa] ++;
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		int cnt = 2;
		for(int j = 0 ; j < k[i] ; j ++)
		{
			int aa = a[i][j], tt = t[i][j];
			if(stsm[aa] == 1)
			{
				spot[aa].push_back({i, 1, tt});
			}
			else
			{
				if(!spot[aa].empty())
				{
					node tmp = spot[aa][spot[aa].size() - 1];
					e[pre[i - 1] + cnt].push_back({pre[tmp.sta - 1] + tmp.id, tmp.co + tt});
					e[pre[tmp.sta - 1] + tmp.id].push_back({pre[i - 1] + cnt, tmp.co + tt});
				}
				e[pre[i - 1] + cnt].push_back({pre[i - 1] + 1, 0});
				e[pre[i - 1] + 1].push_back({pre[i - 1] + cnt, 0});
				spot[aa].push_back({i, cnt, tt});
			}
			cnt ++;
		}
		pre[i] = pre[i - 1] + cnt;
	}//建图
	while(q --)
	{
		int x, y;
		cin >> x >> y;
		int ans = 1e18;
		for(int i = 0 ; i < spot[x].size() ; i ++)
		{
			for(int j = 0 ; j < spot[y].size() ; j ++)
			{
				int xx = pre[spot[x][i].sta - 1] + spot[x][i].id, yy = pre[spot[y][j].sta - 1] + spot[y][j].id;
				dijkstra(xx);
				ans = min(ans, dis[yy] + spot[x][i].co + spot[y][j].co + we[x] + we[y]) ;
			}
		}
		cout << ans << '\n';
	}
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int T = 1;
	while(T --) solve();
	return 0;
}

