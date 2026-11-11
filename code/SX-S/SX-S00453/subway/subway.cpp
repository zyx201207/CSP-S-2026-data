#include <bits/stdc++.h>
using namespace std;
long long w[1000005], k[1000005], lx[505][100005], jh[100005][5];
long long time[505][10005], zb1[505][100005];
long long dt[505][100005];
long long yj;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long c, n, m, d, p;
	cin >> c >> n >> m >> d >> p;
	for (long long i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (long long i = 1; i <= n; i++) {
		cin >> k[i];
		long long a = k[i];
		for (long long j = 1; j <= 2 * a; j++) {
			cin >> lx[i][j] >> time[i][j];
		}
	}
	for (long long i = 1; i <= p; i++) {
		for (long long j = 1; j <= 2; i++) {
			cin >> jh[i][j];
		}
	}

	for (long long i = 1; i <= p; i++) {
		long long sz, wz, sj = 0;
		sz = jh[i][1];
		wz = jh[i][2];
		for (long long i = 1; i <= n; i++) {
			long long ffjh = k[i];
			for (long long j = 1; j <= ffjh; j++) {
				for (long long x = 1; x <= ffjh; x++)
					if (lx[i + 1][x] == lx[i][j]) {
						sj += time[i][j];
						zb1[i][j] = 1;
					}
			}
		}
		for (long long i = 1; i <= n; i++) {
			for (long long j = 1; j <= k[i]; j++) {
				if (zb1[i][j] == 1) {
					for (long long x = j + 1; x <= k[i]; x++) {
						if (zb1[i][j] == zb1[i][x]) {
							break;
						}
						sj += time[i][x];
					}
				}
			}
		}
		cout << w[sz] + w[wz] + sj;
	}
	return 0;
}