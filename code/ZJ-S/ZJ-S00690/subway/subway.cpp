#include<bits/stdc++.h>
using namespace std;
const int N=510+10;
int c,n,m,d,q,tot=1e9,a[510][1010],t[510][1010],w[1005],k[1005];
struct node{
	int v,i,j;
};
vector<node>e[510];
vector<node>g[510];
bool vis[N];
void dfs(int u,int zd,int iu,int ju,int sum)
{
	vis[u]=1;
	if(sum>=tot)
		return;
	if(u==zd)
	{
		if(sum+t[iu][ju]<tot)
		{
			tot=sum+t[iu][ju];
		}
		return;
	}
	for(auto it:g[u])
	{
		int v=it.v;
		if(vis[v])
			continue;
		int iv=it.i;
		int jv=it.j;
		if(jv+1<=k[iv])
		{
			if(iv!=iu)
			{
				dfs(v,zd,iv,jv+1,sum+t[iu][ju]+t[iv][jv]);
			}
			else
			{
				dfs(v,zd,iv,jv+1,sum);
			}
		}
		if(jv-1>0)
		{
			if(iv!=iu)
			{
				dfs(v,zd,iv,jv-1,sum+t[iu][ju]+t[iv][jv]);
			}
			else
			{
				dfs(v,zd,iv,jv-1,sum);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		int last=0;
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			e[a[i][j]].push_back({a[i][j],i,j});
			if(last)
			{
				g[last].push_back({a[i][j],i,j-1});
				g[a[i][j]].push_back({last,i,j});
			}
			last=a[i][j];
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=1e9;
		for(auto it:e[x])
		{
			tot=1e9;
			memset(vis,0,sizeof(vis));
			dfs(x,y,it.i,it.j,0);
			ans=min(ans,tot+w[x]+w[y]+t[it.i][it.j]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}

