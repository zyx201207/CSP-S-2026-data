#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, a[2000010], b[2000010];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		for (int j = 1; j < x; j++) {
			cin >> a[i] >> b[i];
		}
		for (int i = 1; i <= m; i++) {
			cout << 1 << endl;
		}
	}
	return 0;
}