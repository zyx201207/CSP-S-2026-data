#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int C,T,n,k,x,y,m,res,ans,dep[1000010],f[100000][25];
bool vis[1000010];
vector <int> g[1000010];

void DFS(int x,int fa)
{
	dep[x] = dep[f[x][0] = fa] + 1;
	for (int i = 1;i <= 20;i++) f[x][i] = f[f[x][i - 1]][i - 1];
	for (int y : g[x]) if (y != fa) DFS(y,x);
	return;
}

int lca(int x,int y)
{
	if (dep[x] < dep[y]) swap(x,y);
	for (int i = 20;i >= 0;i--) if ((dep[x] - dep[y]) >> i & 1) x = f[x][i];
	if (x == y) return x;
	for (int i = 20;i >= 0;i--) if (f[x][i] != f[y][i]) x = f[x][i],y = f[y][i];
	return f[x][0];
}

void dfs(int x,int cnt)
{
	if (n - x + 1 < cnt) return;
	if (x > n)
	{
		m = 0,res = 0;
		for (int i = 1;i <= n;i++)
		{
			if (!vis[i])
			{
				int d = n;
				for (int j = 1;j <= n;j++) if (vis[j]) d = min(d,dep[i] + dep[j] - dep[lca(i,j)] * 2);
				res = max(res,d);
			}
			else if (!vis[f[i][0]]) m++;
		}
		if (m <= 2) ans = min(ans,res);
		return;
	}
	vis[x] = 0,dfs(x + 1,cnt);
	if (cnt) vis[x] = 1,dfs(x + 1,cnt - 1);
	return;
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&C,&T);
	while (T--)
	{
		scanf("%d%d",&n,&k),ans = n;
		for (int i = 1;i < n;i++) scanf("%d%d",&x,&y),g[x].push_back(y),g[y].push_back(x);
		DFS(1,0),dfs(1,k),printf("%d\n",ans);
		for (int i = 1;i <= n;i++) g[i].clear();
	}
	return 0;
}
