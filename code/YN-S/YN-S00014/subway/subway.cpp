#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll N = 100100;
const int N2 = 550;
const ll INF = 0x3f3f3f3f;
bool testA = false, testB = false, cnet[N2][N2], has[N2][N2];
ll c, n, m, d, q, a[N], ans, w[N], t[N], x, y, times[N];
ll cnt, to[N], nxt[N], head[N], dp[N2][N2];


void flod() {
	//cout << m << endl;
	for (int i = 1; i <= m; i++) {
		for (int j = i + 1; j <= m; j++) {
			if (has[i][j]) {
				//cout << "useful" << endl;
				continue;
			}
			for (int k = i + 1; k < j; k++) {
				if (!cnet[i][k] || !cnet[k][j])
					continue;
				cnet[i][j] = true;
				//cout << "now i=" << i << " j=" << j  endl;
				//ll pre = dp[i][j];
				if (dp[i][j] > dp[i][k] + dp[k][j]) {
					//cout << i << ' ' << j << ' ' << "has" << endl;
					has[i][j] = true;
					dp[i][j] = dp[i][k] + dp[k][j];
					//cout << "up";
					break;
				}
				//cout << "flod dp i:" << i << " j:" << j << " k:" << k << "="
				//     << dp[i][j] << endl;
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dp, INF, sizeof(dp));
	cin >> c >> n >> m;
	cin >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		testA = true;
		ll k_num;
		cin >> k_num;
		if (k_num > 2)
			testA = false;
		for (int j = 1; j <= k_num; j++) {
			cin >> a[j];
			cin >> t[j];
			if (j > 1) {
				for (int k = j - 1; k >= 1; k--) {
					cnet[a[k]][a[j]] = true;
					dp[a[k]][a[j]] = t[j] + t[k];
					//cout << "dp i:" << a[k] << " dp j:" << a[j] << "="
					//     << dp[a[k]][a[j]] << endl;

				}
			}
		}
	}
	flod();
	for (int i = 1; i <= q; i++) {
		cin >> x >> y;
		if (x > y)
			swap(x, y);
		cout << dp[x][y] + w[x] + w[y] << endl;
	}
	return 0;
}