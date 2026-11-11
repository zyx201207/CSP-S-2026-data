#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200005;
int aa[N], a[N];
char cc[N], c[N];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int m = 0;
	for (int i = 1; i <= n; i++) cin >> aa[i] >> cc[i], m += aa[i];
	int t = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (t + aa[i] <= m / 2 || t > m / 2) a[++cnt] = aa[i], c[cnt] = cc[i];
		else a[++cnt] = m / 2 - t, c[cnt] = cc[i], a[++cnt] = t + aa[i] - m / 2, c[cnt]= cc[i];
		t += aa[i];
	}
	int ans = 0, i = 1, j = cnt, x = 1, y = 1;
	while (i <= j) {
		if (x + a[i] - 1 < y) x += a[i], i++;
		else if (y + a[j] - 1 < x) y += a[j], j--;
		else if (c[i] != c[j]) {
			if (x >= y && x + a[i] - 1 <= y + a[j] - 1) ans += a[i], x += a[i], i++;
			else if (x <= y && x + a[i] - 1 >= y + a[j] - 1) ans += a[j], y += a[j], j--;
			else if (x <= y && x + a[i] - 1 <= y + a[j] - 1) ans += x + a[i] - y, x += a[i], i++;
			else ans += y + a[j] - x, y += a[j], j--;
		}
		else {
			if (x >= y && x + a[i] - 1 <= y + a[j] - 1) x += a[i], i++;
			else if (x <= y && x + a[i] - 1 >= y + a[j] - 1) y += a[j], j--;
			else if (x <= y && x + a[i] - 1 <= y + a[j] - 1) x += a[i], i++;
			else y += a[j], j--;
		}
	}
	cout << ans;
	return 0;
}
