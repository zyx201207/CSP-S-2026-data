#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define int long long

struct node
{
	int v, w;
};

int w[500005];
vector <node> g[500010];
// 将线路看作节点 ！！！ 
int chg[500010][20];
int dis[510][510];

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	//    /   |   \  `————\ 
	//线路数 站数 mx线路数 问题数 
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	int t2;
	for(int i = 1; i <= n; i++)
	{
		cin >> t2;
		for(int j = 1; j <= t2; j++)
		{
			int aa, tt;
			cin >> aa >> tt;
			chg[aa][i] = tt;
			// 某个站点的站台到站厅的时间 
		}
	}
	// 将线路看作节点 ！！！ 
	
	// 建图 
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(chg[i][j] == 0)	continue;
			for(int k = j + 1; k <= n; k++)
			{
				if(chg[i][k] == 0)	continue;
				int w = chg[i][j] + chg[i][k];
				node t1 = {j, w}, t2 = {i, w};
				g[i].push_back(t1);
				g[j].push_back(t2);
			}
		}
	}
	
	// 用n遍dj算出全源最短路 
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= n; i++)
	{
		// 枚举起点（是线路） 
		priority_queue <pair<int, int>> q;
		dis[i][i] = 0;
		q.push({0, i});
		while(!q.empty())
		{
			int d = q.top().first;
			int x = q.top().second;
			q.pop();
			d = -d;
			if(d != dis[i][x])	continue;
			for(int i = 0; i < g[x].size(); i++)
			{
				int y = g[x][i].v;
				int w = g[x][i].w;
				if(dis[i][x] + w < dis[i][y])
				{
					dis[i][y] = dis[i][x] + w;
					q.push({-dis[i][y], y});
				}
			}
		}
	}
	
	while(q--)
	{
		int s, t;
		cin >> s >> t;
		int ans = 1e18;
		bool f = false;
		int tt = 0;
		for(int i = 1; i <= n; i++)
		{
			if(chg[s][i] == 0)	continue;
			for(int j = 1; j <= n; j++)
			{
				if(chg[t][j] == 0)	continue;
				if(i == j)
				{
					f = true;
					tt = i;
					break;
				}
				ans = min(ans, dis[i][j] + chg[s][i] + chg[t][j]);
			}
			if(f)	break;
		}
		if(ans == 1e18)	ans = chg[s][tt] + chg[t][tt];
		cout << ans + w[s] + w[t] << endl;
	}
	// 我花了一个半小时敲出来的代码是错的！！！！
	// 啊啊啊啊啊啊啊啊啊啊
	// 怎么可以这样！！！！！！！.
	// QWQQWQQWQQWQQWQQWQQWQQWQQWQ 
	return 0;
}
