#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 15;
ll c, n, k, u[N], v[N], fa[N], dis[N][N];
ll find(ll x) { return (x == fa[x] ? x : fa[x] = find(fa[x])); }
void solve()
{
	scanf("%lld%lld", &n, &k); ll mi = n+1; 
	memset(dis, 0x3f, sizeof(dis));
	for (ll i = 1; i <= n; i++) dis[i][i] = 0;
	for (ll i = 1; i < n; i++) scanf("%lld%lld", &u[i], &v[i]), dis[u[i]][v[i]] = dis[v[i]][u[i]] = 1;
	for (ll k = 1; k <= n; k++)
		for (ll i = 1; i <= n; i++)
			for (ll j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
	for (ll i = 0; i < (1LL<<n); i++)
	{
		ll cnt = 0;
		for (ll j = 1; j <= n; j++) fa[j] = j;
		for (ll j = 0; j < n; j++)
			if ((i>>j)&1) cnt++, fa[j+1] = j+1;
		if (cnt != k) continue;
		for (ll j = 1; j < n; j++)
		{
			if (!((i>>(u[j]-1))&1) || !((i>>(v[j]-1))&1)) continue;
			ll fx = find(u[j]), fy = find(v[j]);
			if (fx != fy) fa[fx] = fy;
		}
		cnt = 0;
		for (ll j = 0; j < n; j++)
			if (((i>>j)&1) && find(j+1) == j+1) cnt++;
		if (cnt <= 2)
		{
			ll mx = 0;
			for (ll j = 1; j <= n; j++)
			{
				ll mm = n+1;
				for (ll k = 0; k < n; k++)
					if ((i>>k)&1) mm = min(mm, dis[j][k+1]);
				mx = max(mx, mm);
			}
//			printf(" %lld\n", mx);
			mi = min(mi, mx);
		}
	}
	printf("%lld\n", mi);
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ll T; scanf("%lld%lld", &c, &T);
	while (T--) solve();
	return 0;
}
