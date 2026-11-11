#include<bits/stdc++.h>

using namespace std;

#define ll long long

const ll maxn=1010;
ll c,n,m,d,p;
ll w[maxn],k[maxn],a[maxn][maxn],t[maxn][maxn];
ll dp[maxn][maxn];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>c>>n>>m>>d>>p;
	for(ll i=1;i<=m;++i)
		cin>>w[i];
	for(ll x=1;x<=m;++x)
		for(ll y=1;y<=m;++y)
			dp[x][y]=1e18;
	for(ll i=1;i<=n;++i)
	{
		cin>>k[i];
		for(ll j=1;j<=k[i];++j)
		{
			cin>>a[i][j]>>t[i][j];
			for(ll xi=1;xi<k[i];++xi)
			{
				ll time=t[i][j]+t[i][xi];
				dp[a[i][xi]][a[i][j]]=time;
				dp[a[i][j]][a[i][xi]]=time;
			}
		}
	}
	for(ll i=1;i<=m;++i)
		for(ll x=1;x<=m;++x)
			for(ll y=1;y<=m;++y)
				dp[x][y]=min(dp[x][y],dp[x][i]+dp[i][y]);
	while(p--)
	{
		ll x,y;
		cin>>x>>y;
		ll ans=w[x]+w[y]+dp[x][y];
		cout<<ans<<endl;
	}
	return 0;
}