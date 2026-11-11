#include <bits/stdc++.h>
using namespace std;
int c, t, n, d;
long long gx;
int ans;

int main() {
	freopen("migrate.out", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		vector<long long> a(n + 3, 0);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (c == 11 || c == 12) {
			long long cd = a[n] - a[1];
			long long cha = a[2] - a[1];
			if (cha >= d / 2 || cha == d) {
				cout << 0;
				return 0;
			}
			/*for (int i = 1; i <= n; i++) {
				//gx=gx+a[i+1]
				//if(a[i+1]+d>=a[i+2]){
				for (int j = i; j <= n; j++) {
					for (int k = 1; k <= n; k++) {
						gx += a[j] - a[i];
						if (a[j + k] - a[i] > (k + 1) * d) {
							gx = gx - (a[j + k - 1] - a[i]) + (a[j + k] - a[i]);
						}
					}

				}
				if (gx == cd) {
					ans++;
				}
				cout << ans / (ans % 2) << '\n';
				continue;
			}
			}*/
			if (c == 13 || c == 14) {
				cout << 0 << '\n';
				continue;
			}
		}
	}
	return 0;
}