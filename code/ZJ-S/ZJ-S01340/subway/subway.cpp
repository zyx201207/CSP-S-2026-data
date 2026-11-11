#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int val=0,k=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') k=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		val=val*10+(ch-'0');
		ch=getchar();
	}
	return val*k;
}
inline void write(long long val)
{
	if(val<0) putchar('-'),val=-val;
	if(val>9) write(val/10);
	putchar(val%10+'0');
}
const int maxM=5e5+5,maxK=2e5+5;
const long long INF=1e15;
int c,n,m,d,q,w[maxM],k[505];
struct nd
{
	int a,t;
	nd(int aa=0,int tt=0) : a(aa),t(tt) { }
};
vector<nd> st[maxM];
long long f[505][505];
int head[505],go[maxK*2],nt[maxK*2],side_siz;
long long cOst[maxK*2],dis[505];
inline void add(int a,int b,long long v)
{
	nt[++side_siz]=head[a];
	head[a]=side_siz;
	go[side_siz]=b;
	cOst[side_siz]=v;
}
bool vis[505];
inline void dij(int u)
{
	for(int i=1;i<=n;i++) dis[i]=INF,vis[i]=0;
	dis[u]=0;
	priority_queue<pair<long long,int> > q;
	q.push(make_pair(0,u));
	for(int i=1;i<n;i++)
	{
		while(vis[q.top().second]) q.pop();
		int now=q.top().second; q.pop();
		vis[now]=true;
		for(int j=head[now];j;j=nt[j])
		{
			int v=go[j];
			long long val=cOst[j];
			if(!vis[v]&&dis[now]+val<dis[v])
				dis[v]=dis[now]+val,q.push(make_pair(-dis[v],v));
		}
	}
	for(int i=1;i<=n;i++) f[u][i]=dis[i];
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(); n=read(); m=read(); d=read(); q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++)
	{
		k[i]=read();
		for(int j=1;j<=k[i];j++)
		{
			int a=read(),tt=read();
			st[a].push_back(nd(i,tt));
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]= ( i==j? 0ll : INF ) ;
	for(int i=1;i<=m;i++)
	{
		int siz=st[i].size();
		for(int l=0;l<siz;l++)
			for(int r=l+1;r<siz;r++)
			{
				int u=st[i][l].a,t_u=st[i][l].t;
				int v=st[i][r].a,t_v=st[i][r].t;
				if(u!=v&&t_u+t_v<f[u][v])
					f[u][v]=f[v][u]=t_u+t_v;
			}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(f[i][j]!=INF)
				add(i,j,f[i][j]),add(j,i,f[j][i]);
	for(int i=1;i<=n;i++) dij(i);
	while(q--)
	{
		int x=read(),y=read();
		long long ans=INF;
		int sizX=st[x].size(),sizY=st[y].size();
		for(int i=0;i<sizX;i++)
			for(int j=0;j<sizY;j++)
			{
				int u=st[x][i].a,t_u=st[x][i].t;
				int v=st[y][j].a,t_v=st[y][j].t;
				ans=min(ans,f[u][v]+w[x]+t_u+t_v+w[y]);
			}
		write(ans),putchar('\n');
	}
	return 0;
}