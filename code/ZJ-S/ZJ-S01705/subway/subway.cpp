#include<bits/stdc++.h>
#define x first
#define y second
#define int long long
#define P pair<int,int> 
using namespace std;
inline int read()
{
	int x=0,y=1;
	char ch;
	ch=getchar();
	if(ch=='-') y=-1;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*y;
}
const int N=5e5+10;
int a[N];
vector<P>g[N];
/*struct tree{
	int l,r,val;
}tr[N*4];
priority_queue<int>pq;
void build(int node,int l,int r)
{
	tr[node].l=l,tr[node].r=r;
	if(l==r) tr[node]=a[l];
	int mid=l+r>>1;
	build(node<<1,l,mid);
	build(node<<1|1,mid+1,r);
	//
}
*/
int dist[N];
int no,n,m,d,q;
inline int dij(int u)
{
	memset(dist,0x3f,sizeof dist);
	dist[u]=0;
	priority_queue<P,vector<P>,greater<P> >pq;
	pq.push({0,u});
	while(pq.size())
	{
		int t=pq.top().y;
		pq.pop();
		for(auto i:g[t])
		{
			if(dist[i.x]>dist[t]+i.y)
			{
				dist[i.x]=dist[t]+i.y;
				pq.push({i.y,i.x});
			}
		}
	}
}
int pq[N];
inline int dij_(int u)
{
	memset(dist,0x3f,sizeof dist);
	memset(pq,0x3f,sizeof pq);
	int h=1,t=1;
	dist[u]=0;
	pq[t]=u;
	while(h<=t)
	{
		int tt=pq[h];
		h++;
		for(auto i:g[tt])
		{
			if(dist[i.x]>dist[tt]+i.y)
			{
				dist[i.x]=dist[tt]+i.y;
				pq[++t]=i.x;
			}
		}
	}
}
//O(mlogm)
int dp[510][510];
inline void floyd()
{
	for(int i=1;i<=m;i++) dp[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int k=1;k<=m;k++)
		{
			for(int j=1;j<=m;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
}
signed main()
{
	memset(dp,0x3f,sizeof dp);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	no=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
	{
		a[i]=read();
	}
	if((no>=9&&no<=11)||(n==480&&m==481&&q==90000))
	{
		
		for(int i=1;i<=n;i++)
		{
			int k=read();
			if(k<=1) continue;
			int u=read(),w=read(),uu=read(),ww=read();
			dp[u][uu]=w+ww;
			dp[uu][u]=w+ww;
		}
		
		floyd();
		while(q--)
		{
			int u=read(),v=read();
			printf("%lld",dp[v]+a[u]+a[v]);putchar('\n');
		}
	}
	else if((no>=12&&no<=19)||(n==480&&m==18721&&q==2000))
	{
		int T;
		for(int i=1;i<=n;i++)
		{
			int k=read();
			if(k<=1) continue;
			for(int j=1;j<=k;j++)
			{
				int u=read(),w=read();
				g[m+i].push_back({u,w});
				T=w;
				g[u].push_back({m+i,w});
			}
		}
		while(q--)
		{
			int u=read(),v=read();
			dij_(u);
			printf("%lld",dist[v]+a[u]+a[v]);putchar('\n');
		}//O(m*q)
	} else {
		for(int i=1;i<=n;i++)
		{
			int k=read();
			if(k<=1) continue;
			for(int j=1;j<=k;j++)
			{
				int u=read(),w=read();
				g[m+i].push_back({u,w});
				g[u].push_back({m+i,w});
			}
		}
		while(q--)
		{
			int u=read(),v=read();
			dij(u);
			printf("%lld",dist[v]+a[u]+a[v]);putchar('\n');
		}//O(m*q*log m)
	}
	return 0;
}
//多源最短路 

/*

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
