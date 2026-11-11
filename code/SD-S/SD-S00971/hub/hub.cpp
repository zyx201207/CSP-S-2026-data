#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,maxx,l,ll;
vector<int>e[1000005];
int d[1000005],s[1000005];
void dfs(int r,int u,int fa,int o)
{
	if(d[u]>maxx)maxx=d[u],l=u;
	for(int i:e[u])
	{
		if(i!=fa)
		{
			d[i]=d[u]+1;
			dfs(r,u,i,o);
			if(o)s[u]+=s[i];
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].emplace_back(v);
			e[v].emplace_back(u); 
		}
		maxx=0,l=1;
		for(int i=1;i<=n;i++)s[i]=1;
		dfs(1,1,0,0);
		for(int i=1;i<=n;i++)d[i]=0;
		maxx=0,ll=l;
		dfs(l,l,0,1);
		cout<<maxx/(k+1);
	}
	return 0;
}

