#include <bits/stdc++.h>
using namespace std;


struct stop {
	int a, t;
};

vector< stop > tostop[500005];
int w[500005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("sudway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			tostop[a].pushback(stop{j, t});
		}
	}
	while (q--) {
		int x, y, ans = 0;
		cin >> x >> y;
		auto spos = tostop[x], epos = tostop[y];
		for (auto samex : spos) {
			int samestopx = samex.a;
			for (auto samey : epos) {
				int samestopy = samey.a;
				if (samestopx == samestopy) {
					ans = w[x] + samex.t + samey.t + w[y];
				}
			}
		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}