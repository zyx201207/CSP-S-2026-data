//感觉有点思路，但是时间不够了，只能爆搜
#include<bits/stdc++.h>

using namespace std;

#define N 100005

int n, K, dis[305][305], dd[N];
struct edge{int u, v;}e[N];

struct DSU
{
	int fa[N];
	void init(){for(int i = 1; i <= n; i++)fa[i] = i;}
	int find(int u){return (fa[u] == u ? u : fa[u] = find(fa[u]));}
	void merge(int u, int v){u = find(u), v = find(v); if(u != v)fa[u] = v;}
}dsu;

signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T >> T;
	while(T--)
	{
		cin >> n >> K;
		if(n <= 30)
		{
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++)
					if(i != j)dis[i][j] = dis[j][i] = 1e9;
					else dis[i][i] = 0;
			for(int i = 1; i < n; i++)cin >> e[i].u >> e[i].v, dis[e[i].u][e[i].v] = dis[e[i].v][e[i].u] = 1;
			for(int k = 1; k <= n; k++)
				for(int i = 1; i <= n; i++)
					for(int j = 1; j <= n; j++)
						if(dis[i][k] < 1e9 && dis[k][j] < 1e9 && dis[i][k] + dis[k][j] < dis[i][j])
							dis[i][j] = dis[j][i] = dis[i][k] + dis[k][j];
			int ans = 1e9;
			for(int sta = 1; sta < (1 << n); sta++)
				if(__builtin_popcount(sta) == K)
				{
					for(int i = 1; i <= n; i++)dd[i] = 1e9;
					dsu.init();
					for(int i = 1; i <= n; i++)
						if((sta >> i - 1 & 1))
							for(int j = 1; j <= n; j++)
								dd[j] = min(dd[j], dis[i][j]);
					for(int i = 1; i < n; i++)
						if((sta >> e[i].u - 1 & 1) && (sta >> e[i].v - 1 & 1))
							dsu.merge(e[i].u, e[i].v);
					map<int, int> mp; mp.clear(); int cnt = 0;
					for(int i = 1; i <= n; i++)
						if((sta >> i - 1 & 1) && !mp[dsu.find(i)])mp[dsu.find(i)] = 1, cnt++;
					if(cnt <= 2)
					{
						int num = 0;
						for(int i = 1; i <= n; i++)num = max(num, dd[i]);
						ans = min(ans, num);
					}
				}
			cout << ans << "\n";
		}
	}
	return 0;
} 
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
