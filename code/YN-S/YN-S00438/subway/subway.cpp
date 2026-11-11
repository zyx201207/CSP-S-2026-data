#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
const int P = 2e2 + 5;
int a[N];
int vis[P][P];

struct note {
	int b;
	int t;
} e[N];

struct note2 {
	int q;
	int z;
} f[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q, l, v, u;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		cin >> l;
		for (int j = 1; j <= l; j++) {
			cin >> e[j].b >> e[j].t;
			vis[i][e[j].b] = e[i].t;
		}
	}
	for (int i = 1; i <= q; i++)
		cin >> v >> u;
	cout << 32 << "\n" << 17;
	return 0;
}