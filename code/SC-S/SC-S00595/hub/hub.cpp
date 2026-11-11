#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7;
int u[N], v[N];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n - 1; i++) {
			cin >> u[i] >> v[i];
		}
		int id = ceil(1.0 * n / k);
		int mx = 0;
		for (int i = id; i <= 2 * id; i++) {
			int dis = min((i - id), (2 * id - i));
			mx = max(mx, dis);
		}
		cout << mx << '\n';
	}
}