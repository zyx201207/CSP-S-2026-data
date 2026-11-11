// 梁伯温 西安辅轮中学 SN-S00349
#include <bits/stdc++.h>
#define inf 0x3f3f3f3ff3f3f3fLL
using namespace std;
const int maxn = 5e5 + 5;

int c, n, m, d, q;
vector<long long> w;
vector<int> k;
int a[maxn][maxn];
long long t[maxn][maxn] 
vector<int> x;
vector<int> y;

void solve() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int j = 1; j <= m; j++) cin >> w[j];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
			cin >> a[i][j] >> t[i][j];
	}
	for (int j = 1; j <= q; j++) cin >> x[j] >> y[j];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out ", "w", stdout);
	long long T = 1;
	while (T--) {
		solve();
	}
	return 0;
}
