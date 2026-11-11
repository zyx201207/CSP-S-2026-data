#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=500010,inf=1e18;
int opt,n,m,d,q,w[maxn],dis[510][510];
struct node
{
	int id,w;
};
vector<node> vt[maxn];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>opt>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];//口到厅dis
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) dis[i][j]=inf;
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++)//地铁编号
	{
		int sum;
		cin>>sum;
		for(int j=1;j<=sum;j++)//经过站点
		{
			int u,s;
			cin>>u>>s;
			int l=vt[u].size();
			for(int k=0;k<l;k++)//该站点其他地铁
			{
				dis[vt[u][k].id][i]=dis[i][vt[u][k].id]=min(dis[i][vt[u][k].id],vt[u][k].w+s);//更新两线路间mindis
			}
			vt[u].push_back({i,s});
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][k]+dis[j][k],dis[i][j]);
		}
	}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		int l1=vt[u].size(),l2=vt[v].size(),ans=inf;
		for(int i=0;i<l1;i++)
		{
			for(int j=0;j<l2;j++) ans=min(ans,dis[vt[u][i].id][vt[v][j].id]+vt[u][i].w+vt[v][j].w);
		}
		cout<<(ans+w[u]+w[v])<<'\n';
	}
	return 0;
}
//不是谁家地铁一线两站，一站两线啊
//CCF我***，你*******