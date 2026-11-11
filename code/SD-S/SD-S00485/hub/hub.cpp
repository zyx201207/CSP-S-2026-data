#include <bits/stdc++.h>
#define LL long long 
using namespace std;
int c, t, n, k;
void solve() {
	cin >> n >> k;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
	}
	if (k == 1) cout << 0 << endl;
	else if (k == 2) cout << 1 << endl;
	else cout << k / 2 + 1 << endl;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}

