#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 5;
ll n,m,c,d,q,w[N],k[505],s,e,di[505][N],ans,g[505][505];
vector<ll> a[505],ti[505],v[505],fa[N];

void bfs(int u)
{
	for(int i = 1;i <= k[u];i++)
	{
		di[u][a[u][i - 1]] = ti[u][i - 1];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			for(int w = 1;w <= n;w++)
			{
				for(int s = 1;s <= k[j];s++)
				{
					di[j][a[j][s - 1]] = min(di[j][a[j][s - 1]],di[w][a[j][s - 1]] + g[w][j]);
				}
			}
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
		{
			int t;
			cin >> t;
			a[i].push_back(t);
			fa[t].push_back(i);
			cin >> t;
			ti[i].push_back(t);
			v[i].push_back(0);
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 0;j < (int)fa[i].size();j++)
		{
			int l = fa[i][j];
			for(int tb = 0;tb < k[l];tb++)
			{
				int v = a[l][tb];
				g[i][v] = min(g[i][v],ti[i][l] + ti[v][l]);
			}
		}
	}
	for(int s = 1;s <= n;s++)
	{
		bfs(s);
		for(int i = 1;i <= n;i++)
		{
			v[i].clear();
			for(int j = 1;j <= k[i];j++)
			{
				v[i].push_back(0);
			}
		}
	}
	for(int i = 1;i <= q;i++)
	{
		cin >> s >> e;
		ans = 0;
		for(int j = 1;j <= n;j++)
		{
			ans = max(di[j][s] + di[s][e],ans);
		}
		cout << ans + w[s] + w[e];
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
