#include<bits/stdc++.h>
#include<bits/extc++.h>
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define fr(x) freopen(#x".in","r",stdin)
#define fw(x) freopen(#x".out","w",stdout)
using namespace std;
namespace P=__gnu_pbds;
using db=double;
using ll=long long;
using ull=unsigned long long;
using PI=pair<ll,int>;
const int N=5e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int a[N];
ll t[N],dis[N*21];
bool vis[N*21];
vector<pair<int,ll>> G[N*21];
inline void dij(int st)
{
	priority_queue<PI,vector<PI>,greater<PI> > q;
	for(int i=1;i<=3*m;i++) 
	{
		vis[i]=0;
		dis[i]=INF;
	}
	dis[st]=0;
	q.push({0,st});
	while(!q.empty())
	{
		int u=q.top().se;
//		cout<<u<<'\n';
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto v:G[u])
		{
			if(dis[v.fi]>dis[u]+v.se)
			{
				dis[v.fi]=dis[u]+v.se;
				q.push({dis[v.fi],v.fi});
			}
		}
	}
	return;
}
int main()
{
	fr(subway);
	fw(subway);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) 
	{
		ll x;
		cin>>x;
		G[i].pb({m+i,x});//站厅和口
		G[m+i].pb({i,x}); 
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		cin>>a[1]>>t[1];
		for(int j=2;j<=x;j++)
		{
			cin>>a[j]>>t[j];
			G[a[j]+m+(m*i)].pb({a[j-1]+m+(m*i),0});
			G[a[j-1]+m+(m*i)].pb({a[j]+m+(m*i),0});
			G[a[j]+m+(m*i)].pb({a[j],t[j]});
			G[a[j]].pb({a[j]+m+(m*i),t[j]});
			G[a[j-1]+m+(m*i)].pb({a[j-1],t[j-1]});
			G[a[j-1]].pb({a[j-1]+m+(m*i),t[j-1]});
			a[j-1]=t[j-1]=0;
		}
	}
	while(q--)
	{
		int st,ed;
		cin>>st>>ed; 
		dij(m+st);
//		for(auto v:G[m+st]) cout<<v.fi<<' ';
//		for(int i=1;i<=m+m*n;i++) cout<<dis[i]<<' ';
//		cout<<'\n';
		cout<<dis[m+ed]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/