#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int c, t;
	int cnt = 1;
	cin >> c >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1, x, y; i < n; i++) cin >> x >> y;
		cout << cnt << "\n";
		++cnt;
	}
	return 0;
}