#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, d, q, dummy;
ll w[500009], k[509];
struct ZPL
{
	ll id, t; //station idx/subway idx, weight
	ZPL () {}
	ZPL (ll idd, ll tt)
	{
		id = idd, t = tt;
	}
};
vector<ZPL> v[509], x[500009];
//d=20 so not sth to worry about
//2e8+4e7+1.2e8
//optimizin' a bit can do
ll dist[509][509];
int main ()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&dummy,&n,&m,&d,&q);
	//saved
	memset (dist, 0x3f, sizeof dist); //INF
	for (int i = 0; i < n; i++) dist[i][i] = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%lld",w+i);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%lld",k+i);
		for (int j = 0; j < k[i]; j++)
		{
			ll vid, vt;
			scanf("%lld%lld", &vid, &vt);
			v[i].push_back(ZPL(--vid,vt));
			x[v[i][j].id].push_back(ZPL(i,v[i][j].t));
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < x[i].size(); j++)
		{
			for (int k = 0; k < j; k++)
			{
				ll ji = x[i][j].id, ki = x[i][k].id;
				dist[ji][ki] = dist[ki][ji] =
				min(dist[ji][ki], x[i][j].t+x[i][k].t);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			for (int k = 0; k < n; k++)
			{
				if (j == k || i == k) continue;
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	for (int i = 0; i < q; i++)
	{
		ll r, s;
		scanf ("%lld%lld", &r, &s);
		r--, s--;
		ll ans = 0x3f3f3f3f3f3f3f3f;
		for (int j = 0; j < x[r].size(); j++)
		{
			for (int k = 0; k < x[s].size(); k++)
			{
				ll ri = x[r][j].id, si = x[s][k].id;
				ans = min (ans, dist[ri][si]+x[r][j].t+x[s][k].t);
			}
		}
		printf("%lld\n",ans+w[r]+w[s]);
	}
	return 0;
}
