#include <bits/stdc++.h>
using namespace std;
const int N=505;
int c,t,n,k,u,v,fa[N],dis[N][N];
bool vis[N];
vector<int>g[N];
int find(int x)
{
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		g[i].clear();
		for(int j=1;j<=n;j++)dis[i][j]=1e9;
		dis[i][i]=0;
		fa[i]=i;
	}
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		dis[u][v]=dis[v][u]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int val=1e9;
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=1;j<=n;j++)fa[j]=j;
		for(int j=1;j<=n;j++)vis[j]=((i>>(j-1))&1);
		for(int j=1;j<=n;j++)if(vis[j])for(auto k:g[j])if(vis[k])fa[find(k)]=find(j);
		int cnt=0,sum=0;
		for(int j=1;j<=n;j++)if(vis[j])cnt+=(j==fa[j]),sum++;
		if(cnt>2||sum!=k)continue;
		int ans=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]){
				int x=1e9; 
				for(int k=1;k<=n;k++)if(vis[k])x=min(x,dis[j][k]);
				ans=max(ans,x);
			}
		}
		val=min(val,ans);
	}
	cout<<val<<'\n';
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}

