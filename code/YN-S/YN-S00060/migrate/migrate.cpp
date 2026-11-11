#include <bits/stdc++.h>
#define ll long long
#define inf (1 << 30)
#define debug printf("------OK------\n");
using namespace std;
const int N = 2E6 + 10;
int c, T;
int n;
ll d, uxy;
int ans;
ll x[N], dd[N];

void calc(int id, int xx, int t, int idy) {
	dd[0] = id, dd[t + 1] = idy;
	bool p = 0;
	for (int i = 1; i <= t + 1; i++) {
		if (dd[i] - dd[i - 1] > d) {
			p = 1;
			break;
		}
	}
	if (!p)
		ans = min(ans, t + 1);
	if (xx >= idy)
		return;
	dd[t + 1] = x[xx];
	calc(id, xx + 1, t + 1, idy);
	calc(id, xx + 1, t, idy);
}

void calc2(int id, int xx, int t, int idy) {
	dd[0] = id, dd[t + 1] = idy;
	bool p = 0;
	for (int i = 1; i <= t + 1; i++) {
		if (dd[i] - dd[i - 1] > d) {
			p = 1;
			break;
		}
	}
	if (!p && t + 1 == ans)
		uxy++;
	if (xx >= idy)
		return;
	dd[t + 1] = x[xx];
	calc2(id, xx + 1, t + 1, idy);
	calc2(id, xx + 1, t, idy);
}

void solve() {
	scanf("%d%lld", &n, &d);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &x[i]);
	if (c == 11 || c == 12) {
		if (d >= 2 * (x[2] - x[1])) {
			printf("%d\n", n - 3);
		} else
			printf("0\n");
		return;
	}
	int tot = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			ans = inf;
			calc(i, i + 1, 0, j);
			uxy = 0;
			calc2(i, i + 1, 0, j);
			if (uxy == 2)
				tot++;
		}
	printf("%d\n", tot);
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &T);
	for (int i = 1; i <= T; i++)
		solve();
	return 0;
}