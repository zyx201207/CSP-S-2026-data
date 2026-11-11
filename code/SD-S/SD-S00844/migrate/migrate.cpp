#include<bits/stdc++.h>
#define Sparkle int main()
#define Sparxie return 0;
#define ll long long
#define Aha cerr<<"hahaha"<<'\n'
#define Lv(x) cerr<<#x<<"="<<x<<'\n'
using namespace std;
const int maxn=2000005;
const int mod=1000000007;
ll dis[maxn];
struct Edge
{
	ll v,val;
};
ll n,d;
vector<Edge> q[5005];
ll dist[5005][5005];
bool vis[5005];
struct Node
{
	ll v,s;
	bool operator < (const Node& oth) const
	{
		return s>oth.s;
	}
};
inline void Dij(ll s)
{
	for(int i=1;i<=n;i++)
	{
		dist[s][i]=INT_MAX;
		vis[i]=0;
	}
	dist[s][s]=0;
	priority_queue<Node> p;
	p.push({s,0});
	Node now;
	while(!p.empty())
	{
		now=p.top();
		p.pop();
		if(vis[now.v])
			continue;
		vis[now.v]=1;
		for(Edge v:q[now.v])
		{
			if(dist[s][v.v]>dist[s][now.v]+v.val)
			{
				dist[s][v.v]=dist[s][now.v]+v.val;
				p.push({v.v,dist[s][v.v]});
			}
		}
	}
}
inline bool check(ll x,ll y)
{
	ll cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(i==x || i==y)
			continue;
		if(dist[x][i]+dist[i][y]==dist[x][y])
		{
			cnt++;
		}
	}
	if(cnt==2)
	{
		return 1;
	}
	return 0;
}
inline void solve()
{
	
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>dis[i];
	}
	for(int i=1;i<=n;i++)
	{
		q[i].clear();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
				continue;
			if(abs(dis[i]-dis[j])<=d)
			{
				q[i].push_back({j,1});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		Dij(i);
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(dist[i][j]==1)
				continue;
			if(check(i,j))
				ans++;
		}
	}
	cout<<ans<<'\n';
}

Sparkle
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,_=1;
	cin>>c>>_;
	while(_--)
	{
		solve();
	}
	Sparxie
}
