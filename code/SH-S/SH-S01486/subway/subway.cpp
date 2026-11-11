#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 500;
const ll M = 500009;
const ll INF = 9223372036854775807;
ll IAKIOI, n, m, d, q, t[M], dst[N + M], mk[N + M];
bool vst[N + M];
vector <ll> to[N + M], w[N + M];

struct Node
{
	ll u, w;
	bool operator<(const Node &a) const
	{
		return w > a.w;
	}
};

ll Dijkstra (ll x, ll y, ll num)
{
	priority_queue <Node> q;
	q.push({ n + x, 0 });
	dst[n + x] = 0;
	while (!q.empty())
	{
		Node p = q.top();
		vst[p.u] = 1;
		if (p.u == n + y) return p.w;
		for (ll i = 0;i < to[p.u].size();i++)
		{
			ll v = to[p.u][i];
			if (mk[v] < num) vst[v] = 0, dst[v] = INF;
			if (vst[v]) continue;
			if (dst[v] <= dst[p.u] + w[p.u][i]) continue;
			dst[v] = dst[p.u] + w[p.u][i];
			mk[v] = num;
			q.push({ v, dst[v] });
		}
		q.pop();
	}
	return -1;
}

int main ()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	/*
		Number meanings
		1 ~ n : Line i
		n + 1 ~ n + m : Station i
	*/
	
	scanf("%lld%lld%lld%lld%lld", &IAKIOI, &n, &m, &d, &q);
	for (ll i = 1;i <= m;i++) scanf("%lld", &t[i]);
	for (ll l = 1;l <= n;l++)
	{
		ll k;
		scanf("%lld", &k);
		for(ll i = 1;i <= k;i++)
		{
			ll a, b;
			scanf("%lld%lld", &a, &b);
			to[l].push_back(n + a);
			to[n + a].push_back(l);
			w[l].push_back(b);
			w[n + a].push_back(b);
		}
	}
	fill(dst + 1, dst + N + M, INF);
	for (ll i = 1;i <= q;i++)
	{
		ll x, y;
		scanf("%lld%lld", &x, &y);
		ll ans = Dijkstra(x, y, i) + t[x] + t[y];
		printf("%lld\n", ans);
	}
	return 0;
}

