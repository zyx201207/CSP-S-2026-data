#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5+10;


vector<ll> jg[MAXN];
ll w[MAXN],c,n,m,d,q,k[MAXN],dist[1010][1010],t[1010][1010];
int b[MAXN][510],a[1010][1010];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dist,0x3f,sizeof(dist));
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(ll i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for(ll i=1;i<=n;i++)
	{
		cin >> k[i];
		for(ll j=1;j<=k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
			jg[a[i][j]].push_back(i);
			b[a[i][j]][i] = j;
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=k[i];j++)
		{
			for(ll cat = 0;cat<jg[a[i][j]].size();cat++)
			{
				if(jg[a[i][j]][cat] == i) continue;
				dist[jg[a[i][j]][cat]][i] = dist[i][jg[a[i][j]][cat]] = min(dist[jg[a[i][j]][cat]][i],t[jg[a[i][j]][cat]][b[a[i][j]][jg[a[i][j]][cat]]] + t[i][j]);
			}
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(i == j) 
			{
				dist[i][j] = 0;
				continue;
			}
			for(ll cat = 1;cat<=n;cat++)
			{
				if(cat == i || cat == j) continue;
				dist[i][j] = min(dist[i][j],dist[i][cat] + dist[cat][j]);
			}
		}
	}
	while(q--)
	{
		ll st,ed;
		cin >> st >> ed;
		ll ans = 1e18;
		for(ll i=0;i<jg[st].size();i++)
		{
			for(ll j=0;j<jg[ed].size();j++)
			{
				ans = min(ans,dist[jg[st][i]][jg[ed][j]] + t[jg[st][i]][b[st][jg[st][i]]] + t[jg[ed][j]][b[ed][jg[ed][j]]]);
			}
		}
		cout << ans + w[st] + w[ed] << endl;
	}
	return 0;
}
