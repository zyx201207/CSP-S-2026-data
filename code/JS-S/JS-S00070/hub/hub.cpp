#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int c,t,n,k,use[N],fa[N],dep[N];
int flag,ans,sum,tot;
vector<int> e[N];
void predfs(int x,int f)
{
	fa[x]=f;
	dep[x]=dep[f]+1;
	for(auto i:e[x])
	{
		if(i==f) continue;
		predfs(i,x);
	}
	return;
}
void dfs(int x,int f,int dis)
{
	if(use[x])
	{
		tot=max(tot,dis);
	}
	for(auto i:e[x])
	{
		if(i==f) continue;
		dfs(i,x,dis+1);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	//cout<<endl;
	if(c==1 or c==2 or c==3)
	{
		while(t--)
		{
			ans=10000010;
			cin>>n>>k;
			for(int i=1;i<=n;i++)
				e[i].clear();
			for(int i=1;i<n;i++)
			{
				int u,v;
				cin>>u>>v;
				e[u].push_back(v); e[v].push_back(u);
			}
			predfs(1,1);
			for(int i=0;i<(1<<(n+1));i++)
			{
				int cnt=0; flag=0; tot=0;
				for(int j=1;j<=n;j++)
				{
					if(i&(1<<j))
					{
						use[j]=1;
						cnt++;
					}
					else
						use[j]=0;
				}
				if(cnt!=k) continue;
				//for(int j=1;j<=n;j++)
				//	cout<<use[j]<<" ";
				//cout<<endl;
				for(int j=1;j<=n;j++)
				{
					if(!use[fa[j]] and use[j]) flag++;
				}
				if(use[1]) flag++;
				//cout<<flag<<endl;
				for(int j=1;j<=n;j++)
				{
					if(!use[j]) dfs(j,j,0);
				}
				//cout<<sum<<endl;
				if(flag<=2) ans=min(ans,tot);
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
