#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5,M=4e6+5;
typedef long long ll;
typedef pair<ll,ll> pll;
int h[N],e[M],ne[M],idx,w[M];
void add(int a,int b,int c)
{
	e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
int c,n,m,d,q;
ll dist[N],cnt[N];
bool st[N];
int x[N],y[N];
void dijkstra(int s,int t)
{
	memset(dist,0x3f,sizeof dist);
	memset(st,0,sizeof st);
	priority_queue<pll,vector<pll>,greater<pll> > q;
	q.push({0,s});
	dist[s]=0;
	while(q.size())
	{
		auto cur=q.top();
		q.pop();
		int u=cur.second;
		if(st[u]) continue;
		st[u]=1;
		for(int i=h[u];i!=-1;i=ne[i])
		{
			int v=e[i];
			if(dist[v]>dist[u]+w[i])
			{
				dist[v]=dist[u]+w[i];
				q.push({dist[v],v});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(h,-1,sizeof h);
	for(int i=1;i<=m;i++)
	{
		int d;
		cin>>d;
		add(i,i+m,d);
		add(i+m,i,d);
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			int a,b;
			cin>>a>>b;
			add(a+m,i+2*m,b);
			add(i+2*m,a+m,b);
		}
	}
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
	for(int i=1;i<=q;i++)
	{
		dijkstra(x[i],y[i]);
		cout<<dist[y[i]]<<'\n';
	}
	return 0;
}
