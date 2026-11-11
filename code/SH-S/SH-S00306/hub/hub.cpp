#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

const int N=1e5+5;

int n,k,res,luogu;
bool vis[40];
vector <int> g[N];

void dfs(int u,int fa)
{
	vis[u]=0;
	
	for (int v:g[u])
	{
		if (v!=fa)
		{
			dfs(v,u);
		}
	}	
}

void findrd(int u,int t,int fa,int dist)
{
	if (u==t)
	{
		luogu=max(luogu,dist);
	}
	
	for (int v:g[u])
	{
		if (v!=fa)
		{
			findrd(v,t,u,dist+1);
		}
	}
}

void solve()
{
	cin >> n >> k;
	res=1e9;
	
	for (int i=1;i<=n;i++) g[i].clear();
	
	for (int i=1;i<n;i++)
	{
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	
	if (k<=2)
	{
		cout << "1\n";
		return ;
	}
	
	for (int mask=0;mask<(1<<n);mask++)
	{
		int cnt=0;
		
		for (int i=0;i<n;i++)
		{
			if (mask&(1<<i)) cnt++;
		}
		
		if (cnt!=k) continue;
		
		memset(vis,0,sizeof vis);
		
		for (int i=0;i<n;i++)
		{
			if (mask&(1<<i)) vis[i+1]=1;
		}
		
		int kkksc=0;
		
		for (int i=1;i<=n;i++)
		{
			if (vis[i])
			{
				kkksc++;
				if (kkksc>=3) goto fail;
				dfs(i,0);
			}
		}
		
		for (int i=0;i<n;i++)
		{
			if (mask&(1<<i)) vis[i+1]=1;
		}
		
		luogu=-1e9;
		
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if (vis[i] && vis[j])
				{
					findrd(i,j,0,0);
				}
			}
		}
		
		res=min(luogu,res);
		fail:continue;
	}
	
	cout << res << "\n";
	return ;
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c,t;
	cin >> c >> t;
	
	while (t--)
	{
		solve();
	}
	
	return 0;
} 

/*∫√≥§“¿Õ–*/
