#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int c, n, m, d, p, str, endd, ans;
int w[N];

struct st {
	int sum;
	int v, t;
} a[N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> a[i].sum;
		for (int j = 1; j <= a[i].sum; j++)
			cin >> a[i].v >> a[i].t;
	}
	while (p--) {
		ans = 0;
		cin >> str >> endd;
		ans += w[str];
		while (str != endd) {
			for (int i = 1; i <= n; i++) {
				if (str == a[1].v) {
					ans += a[1].t;
					ans += a[2].t;
					str = a[2].v;
					break;
				}
			}
		}
		ans += w[endd];
		cout << ans << "\n";
	}

	return 0;
}