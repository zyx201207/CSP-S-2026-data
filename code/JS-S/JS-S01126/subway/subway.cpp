#include<bits/stdc++.h>
using namespace std;
const int N=1e3+100;
const long long INF=1e17;
int c,n,m,d,q,w[N],k[505];
int a[505][N],t[505][N];
long long dis[N][N];
bool vis[N];
struct node{
	int l,p;
};
vector <node> g[N];
int si[N];
long long ans;
void dijksta(int x)
{
	dis[x][x]=0;
	int u=0;
	for(int v=1;v<=m;v++)
	{
		long long minn=INF;
		for(int i=1;i<=m;i++)
		{
			if(vis[i]!=1)
			{
				if(dis[x][i]<minn)
				{
					u=i;
					minn=dis[x][i];
				}
			}
		}
		vis[u]=1;
		for(int i=0;i<si[u];i++)
		{
			for(int j=1;j<=k[g[u][i].l];j++)
			{
				if(vis[a[g[u][i].l][j]]==0)
				{
					dis[x][a[g[u][i].l][j]]=min(dis[x][a[g[u][i].l][j]],dis[x][u]+t[g[u][i].l][g[u][i].p]+t[g[u][i].l][j]);
				}
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
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			g[a[i][j]].push_back((node){i,j});
			si[a[i][j]]++;
		}
	}
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=m;j++)
		{
			dis[i][j]=INF;
			vis[j]=0;
		}
		dijksta(i);
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ans=dis[x][y]+w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}
