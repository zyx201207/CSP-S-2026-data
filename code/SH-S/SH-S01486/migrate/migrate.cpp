#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 5009;
ll c, t, n, x[N], to[N][N], times[N], vst[N];

ll bfs (ll x)
{
	ll res = 0;
	queue <ll> q;
	q.push(x);
	vst[x] = 1;
	while (!q.empty())
	{
		ll u = q.front();
		q.pop();
		for (ll i = u + 1;i <= n;i++)
		{
			if (!to[u][i]) continue;
			if (vst[i] == vst[u] + 1)
			{
				if (times[i] == 2) res--;
				if (times[i] == 1) res++;
				times[i]++;
				continue;
			}
			if (vst[i] < vst[u] + 1 && vst[i]) continue;
			vst[i] = vst[u] + 1;
			times[i] = 1;
			q.push(i);
		}
	}
	fill(vst + 1, vst + N, 0);
	fill(times + 1, times + N, 0);
	return res;
}

int main ()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	for (ll IAKIOI = 1;IAKIOI <= t;IAKIOI++)
	{
		ll d;
		scanf("%lld%lld", &n, &d);
		for (ll i = 1;i <= n;i++) scanf("%lld", &x[i]);
		for (ll i = 0;i < N;i++) for (ll j = 0;j < N;j++) to[i][j] = 0;
		for (ll i = 1;i < n;i++) for (ll j = i + 1;j <= n;j++)
		{
				if (x[j] - x[i] <= d) to[i][j] = 1;
				else j = n;
		}
		ll ans = 0;
		for (ll i = 1;i < n - 2;i++) ans += bfs(i);
		printf("%lld\n", ans);
	}
	return 0;
}
