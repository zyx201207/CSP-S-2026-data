#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second

const int M=500005,N=505;
struct edge{
	int to,dis,nxt;
}e[2*M];
int h[N+M],cnt=0;
void add(int u,int v,int w)
{
	e[++cnt].to=v;
	e[cnt].dis=w;
	e[cnt].nxt=h[u];
	h[u]=cnt;
}

int c,n,m,d,q;
int w[M];


int dis[N+M];
bool vis[N+M];
int dijskra(int fr,int en)
{
	for(int i=1;i<=N+M;i++)
	{
		dis[i]=INT_MAX;
		vis[i]=0;
	}
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	dis[fr]=0;
	pq.push({0,fr});
	while(!pq.empty())
	{
		
		int p=pq.top().se;
		pq.pop();
		if(vis[p])
			continue;
		vis[p]=1;
		for(int i=h[p];i;i=e[i].nxt)
		{
			int k=e[i].to;
			if(dis[k]>dis[p]+e[i].dis)
			{
				dis[k]=dis[p]+e[i].dis;
				pq.push({dis[k],k});
			}
		}
	}
	return dis[en];
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1,v,w;j<=k;j++)
		{
			cin>>v>>w;
			add(i,n+v,w);
			add(n+v,i,w);
		}
	}
	
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dijskra(x+n,y+n)<<'\n';
	}
	return 0;
}
