#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c , t , n , cnt[5005][5005] , cnt2[5005];
long long d , x[N] , f[5005][5005] , s[5005][5005] , f2[5005] , s2[5005] , pre[N];
int main () {
	freopen ("migrate.in" , "r" , stdin);
	freopen ("migrate.out" , "w" , stdout);
	ios::sync_with_stdio (false) , cin.tie (0) , cout.tie (0);
	cin >> c >> t;
	if (c <= 10) {
		while (t--) {
			int ans = 0;
			cin >> n >> d;
			for (int i = 1; i <= n; i++) {
				cin >> x[i];
				int l = 1 , r = i - 1;
				pre[i] = i;
				while (l <= r) {
					int mid = (l + r) / 2;
					if (x[i] - x[mid] <= d) {
						pre[i] = mid;
						r = mid - 1;
					} else {
						l = mid + 1;
					}
				}
				//cout << i << " " << pre[i] << "\n";
			}
			for (int i = n - 1; i >= 1; i--) {
				for (int j = i + 1; j <= n; j++) {
					if (pre[j] == j) {
						f[i][j] = 0;
						s[i][j] = s[i][j - 1] + f[i][j];
						continue;
					}
					if (x[j] - x[i] <= d) {
						cnt[i][j] = 1;
						f[i][j] = 1;
						s[i][j] = s[i][j - 1] + f[i][j];
						continue;
					}
					int l = pre[j] + 1 , r = j - 1 , mx = pre[j];
					while (l <= r) {
						int mid = (l + r) / 2;
						if (cnt[i][mid] == cnt[i][pre[j]]) {
							mx = mid;
							l = mid + 1;
						} else {
							r = mid - 1;
						}
					}
					//if (i == 2 && j == 5) cerr << mx << "\n";
					cnt[i][j] = cnt[i][pre[j]] + 1;
					f[i][j] = s[i][mx] - s[i][pre[j] - 1];
					s[i][j] = s[i][j - 1] + f[i][j];
					if (f[i][j] == 2) ans++;
					//cout << i << " " << j << " " << f[i][j] << "\n";
				}
			}
			cout << ans << "\n";
		}
	} else {
		while (t--) {
			long long ans = 0;
			cin >> n >> d;
			for (int i = 1; i <= n; i++) {
				cin >> x[i];
				
			}
			for (int i = 1; i <= n; i++) {
				pre[i] = max (1ll , (long long)i - d / (x[2] - x[1]));
			}
			for (int i = 2; i <= n; i++) {
				if (pre[i] == i) {
					cnt2[i] = 0;
					f2[i] = 0;
					s2[i] = s2[i - 1];
					continue;
				}
				if (x[i] - x[1] <= d) {
					cnt2[i] = 1;
					f2[i] = 1;
					s2[i] = s2[i - 1] + 1;
					continue;
				}
				int l = pre[i] + 1 , r = i - 1 , mx = pre[i];
				//if (i == 4) cout << l << "]\n";
				while (l <= r) {
					int mid = (l + r) / 2;
					//if (i == 4) cerr << mid << " " << cnt2[mid] << " " << pre[i] << " " << cnt2[pre[i]] << "\n";
					if (cnt2[mid] == cnt2[pre[i]]) {
						mx = mid;
						//if (i == 4) cout << "[" << mid << "\n";
						l = mid + 1;
					} else {
						r = mid - 1;
					}
				}
					cnt2[i] = cnt2[pre[i]] + 1;
					f2[i] = s2[mx] - s2[pre[i] - 1];
					s2[i] = s2[i - 1] + f2[i];
					if (f2[i] == 2) ans += n - i + 1;
					//cout << i << " " << f2[i] << "\n";
					//if (i == 4) cout << mx << "\n";
			}
			//for (int i = 2; i <= n; i++) cout << pre[i] << " ";
			//cout << "\n";
			cout << ans << "\n";
		}
	}
	return 0;
}
