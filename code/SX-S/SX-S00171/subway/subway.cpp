#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 515, M = 5e5+15;
ll w[M];
int k[N];

struct node {
	long long a, t;
};
vector<node> ns[M];
long long dis[N][N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dis, 0x3f, sizeof(dis));
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	long long aa, tt;
	for (int i = 1; i <= n; i++) {
		dis[i][i] = 0;
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; j++) {
			scanf("%lld%lld", &aa, &tt);
			ns[aa].push_back((node) {
				i, tt
			});
		}
	}
	for (int i = 1; i <= m; i++) {
		for (auto j : ns[i]) {
			for (auto kkk : ns[i]) {
				if (j.a != kkk.a) {
					dis[j.a][kkk.a] = min(dis[j.a][kkk.a], j.t + kkk.t);
					dis[kkk.a][j.a] = min(dis[kkk.a][j.a], j.t + kkk.t);
				}
			}
		}
	}
	for (int kkk = 1; kkk <= n; kkk++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j)
					dis[i][j] = min(dis[i][j], dis[i][kkk] + dis[kkk][j]);
			}
		}
	}
	int mystart, myend;
	while (q--) {
		scanf("%d%d", &mystart, &myend);
		long long dse = 1e18;
		for (auto i : ns[mystart]) {
			for (auto j : ns[myend]) {
				if (dis[i.a][j.a] + i.t + j.t < dse) {
					dse = dis[i.a][j.a] + i.t + j.t;
				}
			}
		}
		printf("%lld\n", (ll)(dse + w[mystart] + w[myend]));
	}
	return 0;
}
