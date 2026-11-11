#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct T {
	ll a, t;
} dd[5000000];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll c, n, m, d, q, w[505];
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < m; i++)
		cin >> w[i];
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int a;
			cin >> a >> dd[a].t;
		}
	}
	for (int i = 0; i < q; i++) {
		int u, v;
		ll h = 0;
		cin >> u >> v;
		for (int i = u; i <= v; i++) {
			h += dd[i].t + w[i];
		}
		cout << h << "\n";
	}
	return 0;
}