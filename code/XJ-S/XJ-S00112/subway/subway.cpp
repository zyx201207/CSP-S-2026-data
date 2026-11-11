#include<bits/stdc++.h>
#define rep(i,m,n) for(ll i=m;i<=n;i++)
#define mem(s,t) memset(s,t,sizeof s)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll M=5e5+5,N=505,inf=1e18;
struct edge{ll to,ne,w;}e[M<<1];
struct node
{
	ll id,w;
	friend bool operator <(node a,node b)
	{
		return a.w>b.w;
	}
};
ll c,n,m,g[M],d,q,k[N],idx,h[M<<1],dis[M],s_dis[N][N],vis[M];
void add(ll u,ll v,ll w)
{
	e[++idx].to=v;
	e[idx].w=w;
	e[idx].ne=h[u];
	h[u]=idx;
}
void dijkstra(ll s)
{
	priority_queue<node> q;
	dis[s]=0,q.push({s,0});
	while(q.size())
	{
		node tmp=q.top();
		q.pop();
		ll u=tmp.id;
		if(vis[u])continue;
		vis[u]=1;
		for(ll i=h[u];i!=-1;i=e[i].ne)
		{
			ll v=e[i].to,w=e[i].w;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	mem(h,-1);
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m)cin>>g[i];
	rep(i,1,n)
	{
		cin>>k[i];
		rep(j,1,k[i])
		{
			ll a,t;
			cin>>a>>t;
			add(m+i,a,t),add(a,m+i,t);
		}
	}
	rep(i,1,n)
	{
		rep(j,1,n+m)dis[j]=inf,vis[j]=0;
		dijkstra(m+i);
		rep(j,1,n)s_dis[i][j]=dis[m+j];
	}
	while(q--)
	{
		ll x,y,ans=inf;
		cin>>x>>y;
		for(int i=h[x];i!=-1;i=e[i].ne)
		{
			ll a1=e[i].to,t1=e[i].w;
			for(int j=h[y];j!=-1;j=e[j].ne)
			{
				ll a2=e[j].to,t2=e[j].w;
				ans=min(ans,s_dis[a1-m][a2-m]+t1+t2);
			}
		}
		cout<<ans+g[x]+g[y]<<endl;
	}
    return 0;
}
