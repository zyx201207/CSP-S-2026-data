#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int a[N], b[N];
int n, m;
int ans[N];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int T = n;
	int w = 1;
	while (T--) {
		for (int i = 1; i <= n; i++) {
			if (i < w) {
				b[i] = 0;
				continue;
			}
			b[i] = a[i];
			for (int j = i - 1; j >= w; j--) {
				if (b[j] == b[i]) {
					for (int k = j; k < i; k++) {
						b[k] = 0;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			ans[b[i]]++;
		}
		w++;
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}


