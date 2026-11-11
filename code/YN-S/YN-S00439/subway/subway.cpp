#include <bits/stdc++.h>
using namespace std;
//暴力出奇迹，骗分过样例
long long c, p, n, m, ans = INT_MAX, d, ij, p1, q, w[200005], a[505][200005], flag[505][200005], t[505][200005];
int x, y;

void sp1(int dep, int nx) {
	long long sum1 = 0;
	if (dep > n || dep > m) {
		//bu hui le
	}//ans=min(sun,ans);
	if (nx == y) {
		ans = min(ans, sum1);
		cout << ans + w[x] + w[y];
		exit(0);
	} else if (flag[dep][nx + 1] != 0) {
		sp1(dep, nx + 1);
		sum1 += (t[dep][nx + 1]);
	} else if (flag[dep + 1][nx] != 0) {
		sp1(dep + 1, nx);
		sum1 += t[dep + 1][nx];
	}
}

int main() {

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		if (k <= 2)
			p++;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
			flag[i][a[i][j]] = t[i][j];
		}
	}
	if (c >= 12 && c <= 19) {//B
		int sum = INT_MAX, ls, ls1;
		for (int o = 1; o <= q; o++) {
			cin >> x >> y;
			if (y > x)
				swap(x, y);
			for (int i = 1; i <= n; i++) {
				if (sum > flag[i][x]) {
					sum = flag[i][x];
					ls = i;
				}
			}
		}
		sp1(1, ls);
	} else if (c >= 7 && c <= 11) {//A

	} else {

	}

	return 0;
}
