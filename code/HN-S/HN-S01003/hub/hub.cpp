#include<bits/stdc++.h>
#define pre(i, l, r)	for(int i = (l); i <= (r); ++i)
#define fpre(i, r, l)	for(int i = (r); i >= (l); --i)
#define ll long long

using namespace std;

const int maxn = 2e2 + 5;
const int inf = 1e9;
const ll lnf = 2e18;

int c, t, n, k;
vector<int> edges[maxn];
int dis[maxn][maxn];

void dfs(int k, int x, int fa)
{
	for(auto y : edges[x])
		if(y ^ fa)
			dis[k][y] = dis[k][x] + 1, dfs(k, y, x);
}

int vis[maxn];

void update(int i, int x, int fa)
{
	vis[x] = 1;
	for(auto y : edges[x])
		if((i >> (y - 1) & 1) && y ^ fa)
			update(i, y, x);
}

bool check(int id)
{
	int cnt = 0;
	pre(i, 1, n)	vis[i] = 0;
	pre(i, 1, n)
		if(!vis[i] && (id >> (i - 1) & 1))
			cnt++, update(id, i, -1);
	return cnt <= 2;
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--)
	{
		scanf("%d%d", &n, &k);
		pre(i, 1, n - 1)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			edges[u].emplace_back(v);
			edges[v].emplace_back(u);
		}
		pre(i, 1, n)
			dis[i][i] = 0, dfs(i, i, -1);
		int ans = inf;
		pre(i, 0, (1 << n) - 1)
			if(__builtin_popcount(i) == k && check(i))
			{
				int res = 0;
				pre(x, 1, n)
				{
					int tot = inf;
					pre(y, 1, n)
						if(i >> (y - 1) & 1)
							tot = min(tot, dis[x][y]);
					res = max(res, tot);
				}
				ans = min(ans, res);
			}
		printf("%d\n", ans);
		pre(i, 1, n)	edges[i].clear();
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
