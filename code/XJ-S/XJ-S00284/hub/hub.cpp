#include <iostream>
#include <cmath>
using namespace std;
int main(void) {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i < n; ++i) {
			int u, v;
			cin >> u >> v;
		}
		cout << ceil((n - k) * 1.0 / 6) << '\n';
	}
	return 0;
}
