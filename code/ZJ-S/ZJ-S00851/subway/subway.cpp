#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10000010,INF=0x3f3f3f3f3f3f3f3f;
ll c,n,m,d,q,cost[N],cnt,x,y,dist[N],res[N],ans;
ll h[N],e[N],w[N],ne[N],idx;
bool vis[N];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> heap;
void add(ll x,ll y,ll z)
{
	e[idx]=y,w[idx]=z,ne[idx]=h[x],h[x]=idx++;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(h,-1,sizeof(h));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>cost[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>cnt;
		while(cnt--)
		{
			cin>>x>>y;
			add(x,i+m,y);
			add(i+m,x,y);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n+m;j++)
		{
			dist[j]=INF;
			vis[j]=false;
		}
		dist[i+m]=0;
		heap.push({0,i+m});
		while(heap.size())
		{
			ll u=heap.top().second;
			heap.pop();
			if(vis[u])
			{
				continue;
			}
			vis[u]=true;
			for(ll i=h[u],j,pay;~i;i=ne[i])
			{
				j=e[i],pay=w[i];
				if(dist[j]>dist[u]+pay)
				{
					dist[j]=dist[u]+pay;
					heap.push({dist[j],j});
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			res[(i-1)*m+j]=dist[j];
		}
	}
	while(q--)
	{
		ans=INF;
		cin>>x>>y;
		for(int i=1;i<=n;i++)
		{
			ans=min(ans,res[(i-1)*m+x]+res[(i-1)*m+y]+cost[x]+cost[y]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}