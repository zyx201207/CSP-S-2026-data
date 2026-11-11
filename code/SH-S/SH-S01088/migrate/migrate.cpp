#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000005, inf = 0x3f3f3f3f;
long long x[maxn], dis[maxn];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n;
		long long d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		long long ans = 0;
		for (int i = 1; i <= n - 1; i++) {
			dis[i] = 0;
			for (int j = i + 1; j <= n; j++) {
				int r = 1, cnt = 0;
				long long minn = dis[j - 1] + 1;
				while (j - r >= i && x[j] - x[j - r] <= d) {
					if (dis[j - r] < minn) {
						minn = dis[j - r];
						cnt = 1;
					} else if (dis[j - r] == minn) {
						cnt++;
					}
					r++;
				}
				if (minn == dis[j - 1] + 1) break;
				dis[j] = minn + 1;
				if (cnt == 2) ans++;		
			}
		}
		cout << ans << endl;
	}
	return 0;
}
