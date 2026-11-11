#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=1e18+7;
ll c,n,m,d,q,w[500005],k[505],mind[505][505],g[505][505];
vector<ll> a[505],t[505];
vector<pair<ll,ll> >x[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	for(ll i=0;i<=500;i++)for(ll j=0;j<=500;j++)mind[i][j]=INF;
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++)
	{
		cin>>k[i];
		for(ll j=1;j<=k[i];j++)
		{
			ll tmpa,tmpt;
			cin>>tmpa>>tmpt;
			a[i].push_back(tmpa);
			t[i].push_back(tmpt);
			x[tmpa].push_back(make_pair(i,tmpt));
		}
	}
	for(ll i=1;i<=m;i++)
		for(ll l=0;l<x[i].size()-1;l++)
			for(ll r=l+1;r<x[i].size();r++)
				mind[min(x[i][l].first,x[i][r].first)][max(x[i][l].first,x[i][r].first)]=min(mind[min(x[i][l].first,x[i][r].first)][max(x[i][l].first,x[i][r].first)],1ll*(x[i][l].second+x[i][r].second));
	for(ll l=1;l<=n;l++)for(ll r=1;r<=n;r++)if(mind[l][r]!=INF)g[r][l]=g[l][r]=mind[l][r];
	for(ll l=1;l<=n;l++)for(ll r=1;r<=n;r++)if(g[l][r]==0)g[l][r]=INF;
	for(ll I=1;I<=n;I++)
	{
		for(ll K=1;K<=n;K++)
		{
			if(I==K)continue;
			for(ll J=1;J<=n;J++)
			{
				if(I==J||K==J)continue;
				g[I][J]=min(g[I][J],g[I][K]+g[K][J]);
			}
		}
	}
	for(ll i=1;i<=n;i++)g[i][i]=0;
	for(ll i=1;i<=q;i++)
	{
		ll xx,yy;
		cin>>xx>>yy;
		ll ans=INF;
		for(ll l=0;l<x[xx].size();l++)
			for(ll r=0;r<x[yy].size();r++)
				ans=min(ans,1ll*(x[xx][l].second+x[yy][r].second+g[x[xx][l].first][x[yy][r].first]));
		cout<<ans+w[xx]+w[yy]<<"\n";
	}
	return 0;
}
