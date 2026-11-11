#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 520;

ll c, n, m, d, q, k, x, y;
ll w[N], dis[N], vis[N];

struct node{
	ll a, t;
}p[510];

vector <node> vec[N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
	for (ll i = 1; i <= m; i++)
		scanf("%lld", &w[i]);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &k);
		for (ll j = 1; j <= k; j++) {
			scanf("%lld %lld", &p[i].a, &p[i].t);
			vec[p[i].a].push_back({i+m, p[i].t});
			vec[i+m].push_back({p[i].a, p[i].t});
		}
	}
	while (q--) {
		for (ll i = 1; i <= m+n; i++)
			dis[i] = vis[i] = 0;
		scanf("%lld %lld", &x, &y);
		dis[x] = 0;
		vis[x] = 1;
		for (ll i = 0; i < vec[x].size(); i++) {
			node v = vec[x][i];
			dis[v.a] = w[x] + v.t;
		}
		while (1) {
			ll id = -1;
			for (ll i = 1; i <= m+n; i++) {
				if (!vis[i] && dis[i] && (id==-1 || dis[i]<dis[id]))
					id = i;
			}
			if (id == -1)
				break;
			for (ll i = 0; i < vec[id].size(); i++) {
				node v = vec[id][i];
				if (!vis[v.a] && (!dis[v.a] || dis[id]+v.t<dis[v.a]))
					dis[v.a] = dis[id] + v.t;
			}
			vis[id] = 1;
		}
		printf("%lld\n", dis[y]+w[y]);
	}
	return 0;
}
