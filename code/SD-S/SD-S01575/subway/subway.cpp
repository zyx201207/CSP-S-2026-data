#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define eb emplace_back
#define pll pair<ll,ll>
#define fi first
#define se second 
const int N=2e6+5,M=5e5+502;
const ll inf=0x3f3f3f3f3f3f3f3f;
bool STST;
ll c,n,m,d,qq,w[N];
vector<ll>dis[502];
vector<pll>G[N];
priority_queue<pll,vector<pll>,greater<pll> >q;
bool vis[N];
void dij(int s)
{
	For(i,0,m+n)dis[s].eb(inf);
	For(i,1,m+n)vis[i]=0;
	dis[s][m+s]=0;
	q.push({dis[s][m+s],m+s});
	while(!q.empty())
	{
		int x=q.top().se;
		q.pop();
		if(vis[x])continue;
		vis[x]=true;
		for(auto v:G[x])
		{
			if(dis[s][v.fi]>dis[s][x]+v.se)
			{
				dis[s][v.fi]=dis[s][x]+v.se;
				q.push({dis[s][v.fi],v.fi});
			}
		}
	}
}
bool EDED;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	For(i,1,m)cin>>w[i];
	if(c>=12&&c<=19)
	{
		ll t;
		For(i,1,n)
		{
			int k;
			cin>>k;
			For(j,1,k)
			{
				int a;
				cin>>a>>t;
				G[a].eb(i+m,1);
				G[i+m].eb(a,1);
			}
		}
		For(i,1,n)
		{
			For(j,0,m+n)dis[i].eb(inf);
			For(j,1,m+n)vis[j]=0;
			dis[i][m+i]=0;
			queue<int>q;
			q.push(i+m);
			while(!q.empty())
			{
				int x=q.front();
				q.pop();
				//cout<<x<<endl;
				for(auto v:G[x])
				{
					if(dis[i][v.fi]>dis[i][x]+1)
					{
						dis[i][v.fi]=dis[i][x]+1;
						q.push(v.fi);
					}
				}
			} 
		}
		while(qq--)
		{
			int x,y;
			cin>>x>>y;
			ll ans=inf;
			For(i,1,n)ans=min(ans,dis[i][x]+dis[i][y]);
			cout<<ans*t+w[x]+w[y]<<'\n';
		}
		return 0;
	}
	For(i,1,n)
	{
		int k;
		cin>>k;
		For(j,1,k)
		{
			int a,t;
			cin>>a>>t;
			G[a].eb(i+m,t);
			G[i+m].eb(a,t);
		}
	}
	For(i,1,n)dij(i);
	while(qq--)
	{
		int x,y;
		cin>>x>>y;
		ll ans=inf;
		For(i,1,n)
		{
			ans=min(ans,dis[i][x]+dis[i][y]);
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
