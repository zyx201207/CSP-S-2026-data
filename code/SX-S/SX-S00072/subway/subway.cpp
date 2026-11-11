#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
const ll N=5e5+5;
ll c,n,m,d,qqq,dis[N];
ll w[N],x[N],y[N],sum[N];
bool vis[N];
priority_queue<pll,vector<pll>,greater<pll> > q;
struct BIAN{
	ll to;
	ll num;
};
vector<BIAN> go[N];
void dijkstra(ll l)
{
	while(!q.empty()) q.pop();
	dis[l]=0;
	q.push({0,l});
	while(!q.empty())
	{
		ll now=q.top().second;
		q.pop();
		vis[now]=1;
		for(BIAN i:go[now])
			if(dis[now]+i.num<dis[i.to])
			{
				dis[i.to]=dis[now]+i.num;
				q.push({dis[i.to],i.to});
			}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>qqq;
	for(ll i=1;i<=m;i++)
		cin>>w[i];
	for(ll i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		memset(sum,0,sizeof(sum));
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		for(ll j=1;j<=k;j++)
		{
			cin>>x[j]>>y[j];
			sum[j]=sum[j-1]+y[j];
		}
		for(ll j=1;j<=k;j++)
			for(ll l=j+1;l<=k;l++)
			{
				go[x[j]].push_back({x[l],y[j]+y[l]});
				go[x[l]].push_back({x[j],y[j]+y[l]});
			//	cout<<x[j]<<" "<<x[l]<<"\n";
			}
	}
//	for(ll i=1;i<=m;i++)
//	{
//		cout<<i<<":";
//		for(BIAN j:go[i])
//			cout<<j.to<<" "<<j.num<<"";
//		cout<<"\n";
//	}
	while(qqq--)
	{
		ll l,r;
		cin>>l>>r;
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		dijkstra(l);
		cout<<w[l]+dis[r]+w[r]<<"\n";
	}
	return 0;
}
/*
[32,60]
*/