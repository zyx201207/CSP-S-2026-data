#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 10;
int n, m, sum;
long long a[M], ans;
bool vis[M];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 29; i >= 0; i--) {
		int now = 0;
		for (int j = 1; j <= n; j++) {
			if (vis[j]) continue;
			if (!((a[j] >> i) & 1)) now++;
		}
		if (n - sum - now >= m) {
			ans = ans + (1 << i);
			sum += now;
			for (int j = 1; j <= n; j++) {
				if (vis[j]) continue;
				if (!((a[j] >> i) & 1)) vis[j] = 1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
