#include <bits/stdc++.h>
using namespace std;

int c,T;
long long x[2000010];
long long dp[10010][10010];

int main () {
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);
	cin >> c >> T;
	for (;T--;) {
		int n,d;
		cin >> n >> d;
		for (int i = 1;i <= n;i++) {
			cin >> x[i];
		}
		if (c == 11 || c == 12) {
			long long cha = x[2] - x[1];
			long long en = d / cha;
			if (cha >= d) {
				cout << 0 << "\n";
			} else {
				long long f[n + 1][n + 1];
				memset (f,0,sizeof (f));
				f[1][1] = 1;
					for (int i = 1;i <= n;i++) {
						for (int j = i + 1;j <= n;j++) {
							for (int k = j - en;k < j;k++) {
								f[i][j] += f[i][k];
							}
						}
					}
					//cout << f[1][2] << " " << f[1][3] << " " << f[1][4] << " " << f[1][5] << "\n";
					long long ans = 0;
					for (int i = 1;i <= n;i++) {
						for (int j = i + 1;j <= n;j++) {
							if (f[i][j] == 2) {
								ans++;
							}
						}
					}
				cout << ans << "\n";
			}
			continue;
		}
		long long cha = x[2] - x[1];
		long long f[n + 1][n + 1];
		f[1][1] = 1;
		for (int i = 2;i <= n;i++) {
			f[1][i] = f[1][i - 1];
			for (int j = 1;j < i - 1;j++) {
				int y = i - j;
				if (y * cha <= d) {
					f[1][i] += f[1][j];
				}
			}
		}
		//cout << f[1][2] << " " << f[1][3] << " " << f[1][4] << " " << f[1][5] << "\n";
		long long ans = 0;
		for (int i = 1;i <= n;i++) {
			for (int j = i + 1;j <= n;j++) {
				if (i != 1) {
					f[i][j] = f[1][j] - f[1][i - 1];
				}
				if (f[i][j] == 2) {
					//cout << i << " " << j << "\n";
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
