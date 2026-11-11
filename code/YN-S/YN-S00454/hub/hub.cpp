#include <bits/stdc++.h>
using namespace std;
#define int long long

int c, t, n, m, a, b;
map<int> mp;
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> m;
		for (int j = 1; j < n; j++) {
			cin >> a >> b;
			mp[a][b]++;
		}
		cout << i << '\n';
	}
	return 0;
}