#include<iostream>
#include<queue>
using namespace std;
#define ll long long
#define pii pair<long long,long long>
const int N=2e5+5;
ll c,T;
ll n,d,cnt;
ll a[N];
ll dis[N],vis[N],head[N],cc[N];
struct node{
	ll nxt;
	ll to;
	ll w;
}e[N];
void add(ll u,ll v,ll w)
{
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	e[cnt].w=w;
	head[u]=cnt;
}
void dijkstra(ll s)
{
	for(ll i=1;i<=n;i++) dis[i]=2e18,vis[i]=0,cc[i]=0;
	dis[s]=0;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push({0,s});
	while(!q.empty())
	{
		ll u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt)
		{
			ll v=e[i].to;
			ll w=e[i].w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				cc[v]=1;
				q.push({dis[v],v});
			}
			else if(dis[v]==dis[u]+w) cc[v]++;//cout<<v<<' '<<dis[v]<<'\n';
		}
	}
 } 
void solve()
{
	while(T--)
	{
		cin>>n>>d;
		ll ans=0;
		for(ll i=1;i<=n;i++) cin>>a[i];
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					add(i,j,1);
				}
				else break;
			 } 
		}
		for(ll i=1;i<=n;i++)
		{
			dijkstra(i);
			for(ll j=i+1;j<=n;j++)
			{
				if(cc[j]==2)
				{
					//cout<<i<<' '<<j<<' ';
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
		for(ll i=1;i<=cnt;i++)
		{
			e[i].nxt=e[i].to=e[i].w=head[i]=0;
		}
		cnt=0;
	} 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>>c>>T;
	solve();
	return 0;
}
