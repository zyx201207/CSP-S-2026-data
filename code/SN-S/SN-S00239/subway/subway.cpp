#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,w[500001],a[501][500001],t[501][500001],k;
vector<pair<ll,ll>> e[m+1];
ll dfs(ll u,ll v)
{
	ll sum=0;
	ll r=0;
	for(ll q:e[u])
	{
		r++;
		if(q==y)
		{
			break;
		}
		else
		{
			sum+=2*t[q.frist()][q.second()];
			dfs(q,y);
		}
	}
	return sum;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k;j++)
		{
			for(int l=j+1;l<=k;l++)
			{
				e[j].push_back({i,l});
				e[l].push_back({i,j});
			}
		}
	}
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		ll ans=0;
		ans+=w[x];
		ans+=w[y];
		ans+=dfs(x,y);
		cout<<ans<<endl;
	}
	return 0;
}
