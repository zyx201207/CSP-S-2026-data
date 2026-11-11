#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < m; i++) {
		cin >> w[i];
		ans += w[i];
	}
	for (int i = 0; i < q; i++) {
		cout << ans << endl;
	}
	return 0;
}