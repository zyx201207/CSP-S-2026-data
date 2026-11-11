#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
int a[N], b[N];

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int q, m;
	cin >> q >> m;
	for (int i = 1; i <= m; i++) {
		int n, mm;
		cin >> n >> mm;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i];
		}
	}
	return 0;
}
