#include <bits/stdc++.h>

namespace solve
{
	int c,n,m,d,q;
	std::vector<int> k;
	std::vector<long long> w;
	std::vector<std::vector<int>> a,v;
	std::vector<std::vector<long long>> t,dis,T;
	void main()
	{
		std::cin>>c>>n>>m>>d>>q;
		w.resize(m+1);
		v.resize(m+1);
		T.resize(m+1);
		for(int i=1;i<=m;i++)
			std::cin>>w[i];
		k.resize(n+1);
		a.resize(n+1);
		t.resize(n+1);
		dis.resize(n+1,std::vector<long long>(n+1,(long long)4e18));
		for(int i=1;i<=n;i++)
		{
			std::cin>>k[i];
			a[i].resize(k[i]);
			t[i].resize(k[i]);
			for(int j=0;j<k[i];j++)
			{
				std::cin>>a[i][j]>>t[i][j];
				v[a[i][j]].push_back(i);
				T[a[i][j]].push_back(t[i][j]);
			}
		}
		for(int i=1;i<=n;i++) dis[i][i]=0;
		for(int i=1;i<=m;i++)
			for(int j=0;j<(int)v[i].size();j++)
				for(int k=0;k<(int)v[i].size();k++)
					dis[v[i][j]][v[i][k]]=std::min(T[i][j]+T[i][k],dis[v[i][j]][v[i][k]]);
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dis[i][j]=std::min(dis[i][k]+dis[k][j],dis[i][j]);
		while(q--)
		{
			int x,y;
			long long ans=4e18;
			std::cin>>x>>y;
			for(int i=0;i<(int)v[x].size();i++)
				for(int j=0;j<(int)v[y].size();j++)
					ans=std::min(T[x][i]+dis[v[x][i]][v[y][j]]+T[y][j],ans);
			std::cout<<ans+w[x]+w[y]<<'\n';
		}
	}
}

int main()
{
using namespace std;
#define PROBLEM "subway"
#if 1
	freopen(PROBLEM".in","r",stdin);
	freopen(PROBLEM".out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve::main();
	return 0;
}