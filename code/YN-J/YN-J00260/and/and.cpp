#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long cnt, m, b[N][35], c[35][N], s, d[35], n, f[35], a[N], ans;
long long tot[35];

bool cmp(long long x, long long y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for (long long i = 1; i <= n; i++) {
		long long w = a[i], cnt1 = 0;
		while (w) {
			cnt1++;
			b[i][cnt1] = w % 2;
			w /= 2;
		}
		cnt = max(cnt, cnt1);
	}
	long long flg = 0;
	for (long long j = cnt; j >= 1; j--) {
		if (!flg) {
			for (long long i = 1; i <= n; i++) {
				if (b[i][j]) {
					tot[j]++;
					c[j][tot[j]] = i;
				}
			}
		} else {
			for (long long i = 1; i <= tot[s]; i++) {
				if (b[c[s][i]][j]) {
					tot[j]++;
					c[j][tot[j]] = c[s][i];
				}
			}
		}
		if (tot[j] >= m) {
			s = j;
			flg = 1;
		}
	}
	for (long long j = cnt; j >= 1; j--) {
		if (tot[j] >= m) {
			ans += pow(2, j - 1);
		}
	}
	cout << ans << endl;
	return 0;
}
// by yyy 2026.10.31