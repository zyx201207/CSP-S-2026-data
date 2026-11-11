#include<bits/stdc++.h>
using namespace std;
int n,k,c,t,f[1005],dep[1005],fa[1005],ans=1000;
vector<int>G[1005];
void init(int x,int y)
{
	fa[x]=y;
	for(auto v:G[x])
		if(v!=fa[x])
		{
			dep[v]=dep[x]+1;
			init(v,x);
		}
}
int sum()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(!f[i]) 
		{
			int tot=1000;
			for(int j=1;j<=n;j++)
			{
				if(f[j])
				{
					int ii=i,jj=j;
					if(dep[ii]<dep[jj]) swap(ii,jj);
					while(dep[ii]>dep[jj]) ii=fa[ii];
					while(ii!=jj)
					{
						ii=fa[ii];
						jj=fa[jj];
					}
					tot=min(tot,dep[i]+dep[j]-2*dep[ii]);
				}
			}
			cnt=max(cnt,tot);
		}
	return cnt;
}
void dfs(int x,int y,int z)
{
	if(z==k) {ans=min(ans,sum());return;}
	for(auto v:G[x])
		if(v!=y)
		{
			f[x]=1;
			dfs(v,x,z+1);
			f[x]=0;
			dfs(v,x,z);
		}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;ans=1000;
		if(n==k)
		{
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		init(1,0);
		dfs(1,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}

