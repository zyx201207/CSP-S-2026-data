#include <bits/stdc++.h>
using namespace std;

const int M = 5E3 + 10;
const int INF = 0x3f3f3f3f;
int c, n, m, d, q, k;
int w[M], cnt[M];
int t[M][M], a;
int minn = INF;
int f(int x, int y, int pos) {
	
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, time;
			cin >> a >> time;
			cnt[a]++;
			t[a][i] = t[i][a] = time;
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = w[x] + w[y];
		for (int i = 1; i <= n; i++) {
			
		}
	}
	return 0;
}
