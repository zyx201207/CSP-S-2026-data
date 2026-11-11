#include <bits/stdc++.h>
#define IOS std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
const int N = 1e4 + 5;

struct edge {
	int u, v;
	int time;
};
int w[N], t[N][N];
vector<edge>e[N];
int c, n, m, d, q, k;

signed main() {
	IOS
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		t[i][0] = k;
		for (int j = 1; j <= k; j++) {
			int a, time;
			cin >> a >> time;
			t[i][a] = time;
		}
	}
	for (int l = 1; l <= q; l++) {
		int x, y, ans = LLONG_MAX;
		cin >> x >> y;
		for (int line1 = 1; line1 <= n; line1++) {
			for (int line2 = line1 + 1; line2 <= n; line2++) {
				if (line1 == line2)
					continue;
				for (int step4 = 1; step4 <= t[line2][0]; step4++) {
					for (int step2 = 1; step2 <= t[line1][0]; step2++) {
						if (step2 != x || step4 != y)
							continue;
						for (int step3 = 1; step3 <= t[line2][0]; step3++) {
							for (int step1 = 1; step1 <= t[line1][0]; step1++) {
								if (step1 == step3 && step2 != step3 && step4 != step3 && step2 != step4) {
									ans = min(ans, t[line1][step1] + t[line2][step1] + t[line1][step2] + t[line2][step4] + w[step2] + w[step4]);
								}
							}

						}
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
