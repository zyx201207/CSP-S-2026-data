#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e5+10;
ll c,n,m,d,q;
vector<ll> g[M];
ll k[600];
ll a[600][M];
ll t[600][M];
ll w[M];
struct E{
	ll id;
	ll t;
	ll v;
};
void slv(ll x,ll y)
{
	priority_queue<ll> q;
	ll ans=0;
	q.push(w[x]);
	while(!q.empty())
	{
		int u=q.top();
		q.pop();
		ans+=u;
		for(ll v:g[u])
		{
			for(ll k:g[v])
			{
				if(w[v]+w[k]<w[u])
				{
					w[u]=w[v]+w[k];
					q.push(w[u]);
					ans+=w[u];
				}
			}
		}
	}
	cout<<ans<<'\n'; 
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++)
	{
		cin>>k[i];
		for(ll j=1;j<=k[i];j++)
		{
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=k[i];j++)
		{
			for(ll h=1;h<=n;h++)
			{
				for(ll f=1;f<=k[h];f++)
				{
					if(i==h&&j==f)continue;
					else if(a[i][j]==a[h][f])
					{
						g[i].push_back(h);
						g[h].push_back(i);
						w[i]=t[i][j]*2;
						w[h]=t[h][f]*2;
					}
				}
			}
		}
	}
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		slv(x,y);
	}
}//CCF给分给分CCF给分给分CCF给分给分CCF给分给分CCF给分给分
//CCF分来分来分来CCF分来分来分来CCF分来分来分来CCF分来分来分来
//CCF 你RP+=INF!*LLONG_MAX!^BB(1e(1e9)^1e9+1e9+7)^(1e(1e9)+7)!^2;
//你这么多RP分我点分啊 
/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
