#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;
int gzy, n, m, d, q;
long long w[500003];
vector < pii > t[500003];
long long ch[503][503];
void solve() {
	int st = 0, ed = 0;
	scanf("%d%d", &st, &ed);
	long long res = 10000000000000000ll;
	for (auto station1 : t[st]) {
		for (auto station2 : t[ed]) {
			res = min(res, station1.second + station2.second + ch[station1.first][station2.first]);
		}
	}
	printf("%lld\n", res + w[st] + w[ed]);
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &gzy, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%lld", w + i);
	}
	for (int i = 1; i <= n; i++) {
		int k = 0;
		scanf("%d", &k);
		while (k--) {
			int ls, t1;
			scanf("%d%d", &ls, &t1);
			t[ls].push_back(make_pair(i, t1));
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ch[i][j] = 10000000000000000ll;
			if (i == j) ch[i][j] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		int mx = t[i].size();
		for (int j = 0; j < mx; j++) {
			for (int k = j + 1; k < mx; k++) {
				int l1 = t[i][j].first, l2 = t[i][k].first;
				long long wt = t[i][j].second + t[i][k].second;
				ch[l1][l2] = min(ch[l1][l2], wt);
				ch[l2][l1] = ch[l1][l2];
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				ch[i][j] = min(ch[i][j], ch[i][k] + ch[k][j]);
			}
		}
	}
	while (q--) {
		solve();
	}
	return 0;
}