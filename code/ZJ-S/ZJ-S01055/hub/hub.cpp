#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u,v,maxx,minn,dep[1001];
vector<long long> g[1001];
void dfs(long long u,long long fa)
{
	dep[u]=dep[fa]+1;
	for(long long i:g[u])
	{
		if(i!=fa) dfs(i,u);
	}
}
void dfs1(long long u,long long fa)
{
	dep[u]=min(dep[fa]+1,dep[u]);
	for(long long i:g[u])
	{
		if(i!=fa) dfs1(i,u);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	//if(c==0||c==7)
	//{
		while(t--)
		{
			cin>>n>>k;
			minn=9999999999;
			for(long long i=1;i<=n-1;i++)
			{
				cin>>u>>v;
				g[u].push_back(v);
				g[v].push_back(u);
			}
			for(long long i=1;i<=n;i++)
			{
				for(long long j=i+1;j<=n;j++)
				{
					maxx=0;
					dfs(i,0);
					dfs1(j,0);
					for(long long i=1;i<=n;i++)
					maxx=max(maxx,dep[i]);
					minn=min(maxx,minn);
				}
			}
			cout<<minn-1<<"\n";
		}
	//}
	return 0;	
} 
