#include <bits/stdc++.h>
#define ll long long
#define PIL pair<int, ll>

using namespace std;

const int N = 505;
const int KmaxN = 5e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int ct, n, m, d, q;
ll w[KmaxN];
ll dist[N][N];
vector<PIL> v[KmaxN];

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d", &ct, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) scanf("%lld", &w[i]);
	for (int i = 1, k; i <= n; i++) {
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			int a; ll b;
			scanf("%d%lld", &a, &b);
			v[a].emplace_back(i, b);
		}
	}
	memset(dist, 0x3f, sizeof dist);
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		int sz = v[i].size();
		for (int j = 0; j < sz; j++) {
			for (int k = j + 1; k < sz; k++) {
				int x = v[i][j].first, y = v[i][k].first;
				dist[x][y] = min(dist[x][y], v[i][j].second + v[i][k].second);
				dist[y][x] = dist[x][y];
			}
		}
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					dist[j][i] = dist[i][j];
				}
			}
		}
	}
	
	for (int st, ed; q--;) {
		scanf("%d%d", &st, &ed);
		ll ans = inf;
		for (PIL it1 : v[st]) {
			for (PIL it2 : v[ed]) {
				ans = min(ans, dist[it1.first][it2.first] + it1.second + it2.second);
			}
		}
		printf("%lld\n", ans + w[st] + w[ed]);
	}
	return 0;
}
/*
subway
*/
