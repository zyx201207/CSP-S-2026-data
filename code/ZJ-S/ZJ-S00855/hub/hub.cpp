#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,k,ans=1e9;
vector<int> mp[1010];
int vis[1010];
int s[1010];
int vi[1010];
void f(int x,int sum)
{
	s[x]=min(s[x],sum);
	for(int v:mp[x])
	{
		if(vi[v]==1) continue;
		vi[v]=1;
		f(v,sum+1);
		vi[v]=0;
	}
	return ;
}
bool pd(int xx)
{
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)
		{
			for(int v:mp[i])
			{
				if(v==xx) return 1;
			}
		}
	}
	return 0;
}
int check()
{
	memset(s,0x7f,sizeof(s));
	int mx=-1e9;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)
		{	
			memset(vi,0,sizeof(vi));
			f(i,0);
		}
	}
	for(int i=1;i<=n;i++)
	{
		mx=max(mx,s[i]);
	}
	return mx;
}
void dfs(int x,int ltk,int op)
{
	if(op==n&&x<k) return ; 
	if(ltk>2) return ;
	if(x==k&&ltk<=2)
	{
		ans=min(ans,check());
		return ;
	}
	for(int i=op+1;i<=n;i++)
	{
		if(pd(i)==1)
		{
			vis[i]=1;
			dfs(x+1,ltk,i);
			vis[i]=0;
		} 
		else
		{
			vis[i]=1;
			dfs(x+1,ltk+1,i);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			mp[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		memset(vis,0,sizeof(vis));
		dfs(0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}