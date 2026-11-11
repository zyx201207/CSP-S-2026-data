#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Init ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const int N = 505;
const int M = 5e5 + 5;
const ll INF = 0x3f3f3f3f3f3f;
int c, n, m, d, q;
int cnt[M];
ll w[M], t[N][25], G[N][N];

struct Node {
	int sub;
	ll time;
} subs[M][25];

int main(void) {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j)
				G[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int ac;
			cin >> ac >> t[i][j];
			++cnt[ac];
			subs[ac][cnt[ac]] = {i, t[i][j]};
		}
	}
	//预处理
	for (int sta = 1; sta <= m; sta++) {
		if (cnt[sta] <= 1)
			continue;
		int l = cnt[sta];
		for (int i = 1; i <= l; i++) {
			for (int j = i + 1; j <= l; j++) {
				int s1 = subs[sta][i].sub, s2 = subs[sta][j].sub;
				ll t1 = subs[sta][i].time, t2 = subs[sta][j].time;
				G[s1][s2] = min(G[s1][s2], t1 + t2);
				G[s2][s1] = min(G[s2][s1], t1 + t2);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (G[i][k] == INF || i == k)
				continue;
			for (int j = i + 1; j <= n; j++) {
				if (G[k][j] == INF || k == j)
					continue;
				if (G[i][k] + G[k][j] < G[i][j]) {
					G[i][j] = G[i][k] + G[k][j];
					G[j][i] = G[i][j];
				}
			}
		}
	}
	//解决
	while (q--) {
		int x, y;
		ll ans = INF;
		cin >> x >> y;

		int l1 = cnt[x], l2 = cnt[y];
		for (int i = 1; i <= l1; i++) {
			for (int j = 1; j <= l2; j++) {
				int s1 = subs[x][i].sub, s2 = subs[y][j].sub;
				ll t1 = subs[x][i].time, t2 = subs[y][j].time;
				if (G[s1][s2] == INF)
					continue;
				ll cur = w[x] + t1 + w[y] + t2 + G[s1][s2];
				ans = min(ans, cur);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}