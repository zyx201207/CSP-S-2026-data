#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 1e6;
int c, t;
int n, k;
int u[N], v[N];
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			cin >> u[i] >> v[i];
		}
		cout << k - 1 << endl;
	}
	return 0;
}
