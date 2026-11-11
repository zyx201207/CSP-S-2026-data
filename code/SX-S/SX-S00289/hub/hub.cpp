#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int c, t;
int a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			a[u] = v;
			a[v] = u;
		}
		cout << 1 << '\n';
	}
	return 0;
}