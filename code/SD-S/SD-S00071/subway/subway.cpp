#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define reg register
int n, m, c, d, q, w[500001], k[501], vis[1000001], dis[1000001], ans[500001], a[500001], t[500001];
struct node {
	int to, w;
};
struct info {
	int x, y, id;
}z[500001];
bool cmp (info a, info b) {
	return a.x < b.x;
}
vector<node> e[1000001];
priority_queue<pair<int, int> > p;
inline void dij (int s) {
	for (int i = 1; i <= 2 * m; i++)
	 dis[i] = LLONG_MAX;
	 for (int i = 1; i <= 2 * m; i++)vis[i] = 0;
	dis[s] = 0;
	p.push(make_pair(0, s));
	while(!p.empty()) {
		int x = p.top().se;p.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		int siz = e[x].size() - 1;
		for (reg int i = 0; i <= siz; ++i) {
			int xx = e[x][i].to, yy = e[x][i].w;
				if (dis[xx] > dis[x] + yy) {
					dis[xx] = dis[x] + yy;
					p.push(make_pair(-dis[xx], xx));
				}
		}
	}
}
signed main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for (reg int i = 1; i <= m; ++i) {
		scanf("%lld", &w[i]);
		e[i].push_back({i + m, w[i]});
		e[i + m].push_back({i, w[i]});
	}
	for (reg int i = 1; i <= n; ++i) {
		scanf("%lld", &k[i]);
		for (int j = 1; j <= k[i]; j++) {
			scanf("%lld%lld", &a[j], &t[j]);
		}
		//cout << 1;
		for (reg int j = 1; j <= k[i]; ++j) {
			for (reg int l = j + 1; l <= k[i]; ++l) {
				e[a[j] + m].push_back({a[l] + m, t[j] + t[l]});
				e[a[l] + m].push_back({a[j] + m, t[j] + t[l]});
			}
		}
	}
	for (reg int i = 1; i <= q; ++i) {
		scanf("%lld%lld", &z[i].x, &z[i].y);z[i].id = i;
		if (z[i].x > z[i].y) swap(z[i].x, z[i].y);
	}
	sort(z + 1, z + q + 1, cmp);
	for (reg int i = 1; i <= q; ++i) {
		if (z[i].x != z[i - 1].x) {
			dij(z[i].x);
			ans[z[i].id] = dis[z[i].y];
		}else ans[z[i].id] = dis[z[i].y];
	}
	for (reg int i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
