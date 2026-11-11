#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m, f[N], maxx = 0;

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
	}
	sort(f + 1, f + n + 1);
	for (int i = n; i >= 1; i--) {
		int o = m, ans = 1, u = f[i];
		for (int j = i - 1; j >= 1; j--) {
			if (u - f[j] > o)
				break;
			o = o - u + f[j];
			ans++;
		}
//		if (maxx <= ans)
//			cout << u << endl;

		maxx = max(maxx, ans);
	}
	cout << maxx;
	return 0;
}
