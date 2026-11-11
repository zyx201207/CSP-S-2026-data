#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int c,n,m,d,qu;
struct st
{
	int y;ll z;
};
vector<st> e[N];
ll v[N];
ll f[510][510];
int head[N*2],nxt[N*2],to[N*2],tot=1;
ll w[N*2];
ll ans[510][510],dis[510];
int vis[510];
void add(int x,int y,ll z)
{
	nxt[++tot]=head[x];
	head[x]=tot;
	to[tot]=y;
	w[tot]=z;
}
struct node
{
	int x;ll d;
	friend bool operator<(const node &a,const node &b){return b.d<a.d;}
};
priority_queue<node> q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&qu);
	for(int i=1;i<=m;i++) scanf("%lld",&v[i]);
	for(int i=1;i<=n;i++)
	{
		int k;scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int a;ll t;scanf("%d%lld",&a,&t);
			e[a].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;++i)
	{
		int len=(int)e[i].size();
		for(int x=0;x<len;++x)
		{
			int u=e[i][x].y;
			for(int y=x+1;y<len;++y)
			{
				int v=e[i][y].y;
				f[u][v]=min(f[u][v],e[i][x].z+e[i][y].z);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			f[i][j]=min(f[i][j],f[j][i]);
			add(i,j,f[i][j]);add(j,i,f[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++) dis[j]=1e18,vis[j]=0;
		q.push({i,0});dis[i]=0;
		while(!q.empty())
		{
			int x=q.top().x;q.pop();
			if(vis[x]) continue;
			vis[x]=1;
			for(int i=head[x];i;i=nxt[i])
			{
				int y=to[i];
				if(dis[y]>dis[x]+w[i])
				{
					dis[y]=dis[x]+w[i];
					q.push({y,dis[y]});
				}
			}
		}
		for(int j=1;j<=n;j++) ans[i][j]=dis[j];
	}
	while(qu--)
	{
		int x,y;scanf("%d%d",&x,&y);
		int len1=(int)e[x].size(),len2=(int)e[y].size();
		ll res=1e18;
		for(int i=0;i<len1;i++)
		{
			int u=e[x][i].y;
			for(int j=0;j<len2;j++)
			{
				int v=e[y][j].y;
				res=min(res,ans[u][v]+e[x][i].z+e[y][j].z);				
			}
		}
		printf("%lld\n",res+v[x]+v[y]);
	}
	return 0;
}