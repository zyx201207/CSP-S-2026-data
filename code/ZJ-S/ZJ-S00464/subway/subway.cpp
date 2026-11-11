#include<bits/stdc++.h>
using namespace std;
int w[500010];
int e[1010][1010];
int vis[1010];
int a[1010];
int t[1010];
int st,ed;
int c,n,m,d,q;
int dfs(int u)
{
	vis[u]=1;
	int mi=2e9;
	for(int i=1;i<=m;i++)
	{
		if(vis[i]==1||i==u||e[u][i]==0)continue;
		if(i==ed)
		{
			mi=min(mi,e[u][i]);
		}
		else
		{
			int t=dfs(i);
			mi=min(mi,t+e[u][i]);
		}
	}
	return mi;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=x;j++)
		{
			for(int k=1;k<=x;k++)
			{
				e[a[j]][a[k]]=t[j]+t[k];
				e[a[k]][a[j]]=t[j]+t[k];
			}
		}
	}
	while(q--)
	{
		memset(vis,0,sizeof(vis));
		cin>>st>>ed;
		int ans=w[st]+w[ed]+dfs(st);
		cout<<ans<<"\n";
	}
	return 0;
}
