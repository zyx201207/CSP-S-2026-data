#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int> g[1000010];
int dep[1000010];
bool deg2[1000010];
int dep2[1000010];
int maxn,p;

void dfs1(int u,int pa)
{
	for(int i = 0;i < g[u].size();i++)
	{
		int v = g[u][i];
		if(v == pa)continue;
		dfs1(v,u);
		dep[u] = max(dep[u],dep[v] + 1);
	}
}

void dfs2(int u,int pa)
{
	dep2[u] = dep2[pa] + 1;
	if(dep2[u] > maxn)maxn = dep2[u],p = u;
	for(int i = 0;i < g[u].size();i++)
	{
		int v = g[u][i];
		if(!deg2[v])continue;
		if(v == pa)continue;
		dfs2(v,u);
	}
}

bool check(int mid)
{
	memset(deg2,0,sizeof(deg2));
	memset(dep2,0,sizeof(dep2));
	int sum = 0;
	for(int u = 1;u <= n;u++)
		if(dep[u] >= mid)
		{
			sum++;
			int cnt = 0;
			for(int i = 0;i < g[u].size();i++)
			{
				int v = g[u][i];
				if(dep[v] >= mid)cnt++;
				if(cnt > 2)break;
			}
			if(cnt == 2)deg2[u] = 1;
		}
	for(int i = 1;i <= n;i++)
		if(dep2[i] == 0)
		{
			maxn = 0;
			dfs2(i,i);
			dfs2(p,p);
			if(sum - min(maxn,2 * mid) <= k)
				return 1;
		}
	return 0;
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		memset(dep,0,sizeof(dep));
		cin >> n >> k;
		for(int i = 1;i <= n;i++)g[i].clear();
		for(int i = 1;i < n;i++)
		{
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs1(1,0);
		int l = 0,r = n;
		while(l < r)
		{
			int mid = (l + r) / 2;
			if(check(mid))r = mid;
			else l = mid + 1;
		}
		cout << l << '\n';
	}
	return 0;
}
