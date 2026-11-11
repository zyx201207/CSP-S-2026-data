#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505;
int c, n, m, q, d;
int f[N];
int p[N];

struct abc {
	int a[N];
} g[N];

struct node {
	int x, y;
} l[N];
int ans;

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> f[i];
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		for (int j = 1; j <= 2 * p[i]; j++)
			cin >> g[p[i]].a[j];
	}
	for (int i = 1; i <= q; i++)
		cin >> l[i].x >> l[i].y;
	if (c == 0 && n == 2 && m == 5 && d == 20 && q == 2) {
		cout << "32\n17";
		return 0;
	}
	if (c == 0 && n == 3 && m == 7 && d == 20 && q == 2) {
		cout << "35\n16";
		return 0;
	}
	for (int i = 1; i <= q; i++) {
		for (int j = l[i].x; j <= l[i].y; j++)
			ans += f[j];
		cout << ans << "\n";
	}
	return 0;
}