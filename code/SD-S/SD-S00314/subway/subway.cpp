#include<bits/stdc++.h >
using namespace std;
const int N = 5e5 + 500 + 5;
const int M = 1e6 + 5;
int c,n,m,d,q,w[N],cnt,head[N];
long long dis[N];
bool is_fixed[N];
struct edge
{
	int to,nxt,val;
}e[M];
void addedge(int x,int y,int z)
{
	e[++cnt].to = y;
	e[cnt].val = z;
	e[cnt].nxt = head[x];
	head[x] = cnt;
}
void dijkstra(int s)
{
	priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
	for(int i = 1;i <= m + n;i++) dis[i] = (1ll << 62);
	for(int i = 1;i <= m + n;i++) is_fixed[i] = false; 
	dis[s] = 0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int x = q.top().second;
		q.pop();
		if(is_fixed[x]) continue;
		is_fixed[x] = true;
		for(int i = head[x];i;i = e[i].nxt)
		{
			if(dis[e[i].to] > dis[x] + e[i].val)
			{
				dis[e[i].to] = dis[x] + e[i].val;
				q.push(make_pair(dis[e[i].to],e[i].to)); 
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++) scanf("%d",&w[i]);
	for(int i = 1;i <= n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j = 1;j <= k;j++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			addedge(x,m + i,y);
			addedge(m + i,x,y);
		}
	}
	for(int i = 1;i <= q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		dijkstra(x);
		printf("%lld\n",dis[y] + w[x] + w[y]);
	}
	return 0;
}
