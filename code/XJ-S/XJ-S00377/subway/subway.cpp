#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long
#define pii pair<long long,long long>
const int N=5e5+5;
ll c,n,m,d,q;
ll cnt;
ll ww[N],head[N<<1],ans[N],dis[N],vis[N];
struct node{
	ll nxt;
	ll to;
	ll w;
}e[N<<1];
struct node1{
	ll id;
	ll l;
	ll r;
}qu[N];
bool cmp(node1 x,node1 y)
{
	return x.l<y.l;
}
void add(ll u,ll v,ll w)
{
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	e[cnt].w=w;
	head[u]=cnt;
}
void dijkstra(ll s)
{
	for(int i=1;i<=m;i++) dis[i]=1e18,vis[i]=0;
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
				q.push({dis[v],v});
			}
		}
	}
 } 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>ww[i];
	for(int i=1;i<=n;i++)
	{
		ll k,a1,t1,a2,t2;
		cin>>k;
		if(k==1) continue;
		cin>>a1>>t1>>a2>>t2;
		ll w=(t1+t2);
		add(a1,a2,w);
		add(a2,a1,w);
	}
	for(int i=1;i<=q;i++)
	{
		cin>>qu[i].l>>qu[i].r;
		qu[i].id=i;
	}
	sort(qu+1,qu+q+1,cmp);
	for(int i=1;i<=q;i++)
	{
		if(qu[i].l!=qu[i-1].l)
		{
			dijkstra(qu[i].l);
		}
		ans[qu[i].id]=ww[qu[i].l]+ww[qu[i].r]+dis[qu[i].r];
	}
	for(int i=1;i<=q;i++)
	{
		cout<<ans[i]<<'\n';
	}
	return 0;
 } 
