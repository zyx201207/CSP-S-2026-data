#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD=INT_MAX;
const int MAXN=2e5;
int c,n,m,d,q;
ll w[MAXN+5],k[MAXN+5];
int a[505][MAXN+5],t[MAXN+5][505];
ll ans[100005];
struct Question{int x,y,id;} qst[100005];
bool cmp(Question a,Question b) {return a.x<b.x;};

int cnt,head[MAXN+5];
struct Node{int from,to,nxt,val;} edge[MAXN*4+5];
void add(int u,int v,int w=1)
{
	cnt++;
	edge[cnt].from=u;
	edge[cnt].to=v;
	edge[cnt].val=w;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}

priority_queue<pair<ll,pair<int,int>>> pq;
ll dis[MAXN+5][505],dis2[MAXN+5];
bool vis[MAXN+5],ins[MAXN+5];
int bfs(int s)
{
	memset(vis,0,sizeof(vis));
	memset(dis,-1,sizeof(dis));
	memset(dis2,-1,sizeof(dis2));
	dis[s][0]=dis2[s]=0;
	pq.push({0,{s,0}});
	while (!pq.empty())
	{
		ll d=pq.top().first;
		int u=pq.top().second.first;
		int last=pq.top().second.second;
		pq.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (int i=head[u];i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			int w=edge[i].val;
			if (vis[v]) continue;
			ll cost=(w==last?0:(ll)t[w][u]+(ll)t[last][u]);
			if (dis[v][w]==-1||d+cost+t[w][v]<dis[v][w])
			{
				dis[v][w]=d+cost+t[w][v];
				if (dis2[v]==-1||dis[v][w]>dis2[v])
					dis2[v]=dis[v][w];
				pq.push({d+cost,{v,w}});
			}
		}
	}
}

void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
int main()
{
	init();
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=k[i];j++)
		{
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			if (j>=2)
			{
				add(a[i][j-1],a[i][j],i);
				add(a[i][j],a[i][j-1],i);
			}
		}
	}
	for (int i=1;i<=q;i++)
	{
		cin>>qst[i].x>>qst[i].y;
		qst[i].id=i;
	}
	sort(qst+1,qst+1+q,cmp);
	for (int i=1;i<=q;i++)
	{
		bfs(qst[i].x);
		ans[qst[i].id]=dis2[qst[i].y]+w[qst[i].x]+w[qst[i].y];
	}
	for (int i=1;i<=q;i++) cout<<ans[i]<<endl;
	return 0;
}
