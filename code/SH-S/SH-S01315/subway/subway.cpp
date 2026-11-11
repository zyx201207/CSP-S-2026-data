#include<bits/stdc++.h>
using namespace std;
int x,y;
int minn,c,n,m,d,q,w[1005],a[505][1005],t[505][1005],k[505],vis[505],q1[1005][505],s[1005];
void dfs(int u,int y,int fa,bool is_zhanting,int ans,int x)
{
	if(is_zhanting==1&&u==y)
	{
		minn=min(minn,ans);
	}
	else if(is_zhanting==1)
	{
		vis[u]=1;
	for(int i=1;i<=s[u];i++)
	{
		if(q1[u][i]==fa) continue;
		dfs(q1[u][i],y,u,0,ans+t[q1[u][i]][u],x);
	}
	vis[u]=0;
	}else
	if(is_zhanting==0)
	{
		
	for(int i=1;i<=k[u];i++)
	{
		if(vis[a[u][i]]==1||a[u][i]==fa||a[u][i]==x) continue;
		dfs(a[u][i],y,u,1,ans+t[u][a[u][i]],x);}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			s[a[i][j]]++;
			q1[a[i][j]][s[a[i][j]]]=i;
		}
	}
	for(int i=1;i<=q;i++)
	{
		memset(vis,0,sizeof(vis));
		cin>>x>>y;
		minn=0x3f3f3f3f;
		dfs(x,y,-1,1,w[x]+w[y],x);
		cout<<minn<<"\n";
	}
	return 0;
}

