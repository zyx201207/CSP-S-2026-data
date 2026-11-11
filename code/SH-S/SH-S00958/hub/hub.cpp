#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf=1e18;
int c,t,n,k;
bool col[25];
vector<int> g[25];

int zhao(int u,int fa)
{
	if(col[u])
	{
		return 0;
	}
	int ret=inf;
	for(auto v:g[u])
	{
		if(v==fa)
		{
			continue;
		}
		ret=min(ret,zhao(v,u)+1);
	}
	return ret;
}

int check()
{
	int ret=0;
	for(int i=1;i<=n;i++)
	{
		ret=max(ret,zhao(i,0));
	}
	return ret;
}

int lian_kuai(int u,int fa)
{
	int ret=col[u];
	for(auto v:g[u])
	{
		if(v==fa)
		{
			continue;
		}
		if(col[u] and col[v])
		{
			ret+=(lian_kuai(v,u)-1);
		}
		else
		{
			ret+=lian_kuai(v,u);
		}
	}
	return ret;
}

int dfs(int i,int kexuan)
{
	if(i==n+1)
	{
		if(lian_kuai(1,0)<=2)
		{
			if(kexuan==0)
			{
				return check();
			}
		}
		return inf;
	}
	int ret=dfs(i+1,kexuan);
	/*if(ret==1)
	{
		cout<<"!!!"<<i<<" "<<0<<" "<<kexuan<<endl;
		return 1;
	}*/
	if(kexuan)
	{
		col[i]=1;
		int tmp=dfs(i+1,kexuan-1);
		ret=min(ret,tmp);
		col[i]=0;
	}
	return ret;
}
 
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t-->0)
	{
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<dfs(1,k)<<endl;
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
		}
	}
	return 0;
}

