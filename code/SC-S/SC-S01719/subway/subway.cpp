#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e3;
ll c,n,m,d,q;
ll w[N];
ll e[N][N];
// f[i][j]表示从i->j所需的最下路线；
//if(e[u][i]!= MAX_INT) f[i][j][k] = min(f[i][j],f[i][k]+e[k][j]; 
ll f[N][N];
vector<pair<ll,ll> >g[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c>>n >> m >> d >> q;
	for(int i = 1; i <= m+n;i++)
	{
		for(int j = 1; j <= m+n;j++)
		{
			f[i][j] = (ll)1e17;
		}
	}
	for(int i  = 1; i<=m; i++)
	{
		cin >> w[i];
	}
	for(int i = 1; i <= n;i++)
	{
		ll k;
		cin >> k;
		for(int j = 1; j <= k;j++)
		{
			ll ai,ti;
			cin >> ai >> ti;
			f[i+m][ai] = ti;
			f[ai][i+m] = ti;
		}
	}
	for(int k = 1;k <= m+n; k++)
	{
		for(int i = 1; i <= m+n;i++)
		{
			for(int j = 1; j <= m+n;j++)
			{
				if(f[i][k] != 1e17&& f[k][j] != 1e17) f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--) 
	{
		ll x,y;
		cin >> x>>y;
		cout<<f[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}