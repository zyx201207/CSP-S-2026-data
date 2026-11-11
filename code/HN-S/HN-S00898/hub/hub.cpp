#include <bits/stdc++.h>

namespace solve
{
	int n,ans;
	std::vector<std::vector<int>> T,dis;
	std::vector<bool> vis;
	struct mergeset
	{
		std::vector<int> f;
		void resize(int n){f.resize(n);std::iota(f.begin(),f.end();f++);}
		int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
		void merge(int x,int y){f[find(x)]=find(y);}
	}dsu;
	int check()
	{
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]) continue;
			for(int j:T[i])
			{
				if(!vis[i]) continue;

			}
		}
	}
	void dfs(int u=1)
	{
		if(u==n+1)
		{
			ans=std::min(check(),ans);
			return;
		}
		vis[u]=true;
		dfs(u+1);
		vis[u]=false;
		dfs(u+1);
	}
	void main1()
	{
		ans=n;
	}
	void main(int _c)
	{
		std::cin>>n;
		T.assign(n+1,{});
		for(int i=1,u,v;i<n;i++)
		{
			std::cin>>u>>v;
			T[u].push_back(v);
			T[v].push_back(u);
		}
	}
}

int main()
{
using namespace std;
#define PROBLEM "hub"
#if 1
	freopen(PROBLEM".in","r",stdin);
	freopen(PROBLEM".out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;std::cin>>c>>T;
	while(T--) solve::main(c);
	return 0;
}