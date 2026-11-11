#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
ll c, n, m, d, q;
ll w[maxn];

struct edge {
	ll id, t;
};
vector<edge> g;
ll a[maxn];
int t1;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		for (int i = 1; i <= x; i++) {
			cin >> a[i] >> t1;

		}
	}
	while (q--) {
		cin >> s >> e;
		cout << w[s] + w[e] << endl;
	}
	return 0;
}