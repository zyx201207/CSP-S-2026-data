//T3
#include <bits/stdc++.h>
using namespace std;
long long n, m, a[2000005], ans, d[2000005];
int b[2000005][40], c[100], e[2000005][40];

void f(long long x, int o) {
	int cnt = 0;
	while (x != 0) {
		b[o][++cnt] = x % 2;
		x /= 2;
	}
}

long long poww(int o) {
	long long cnt = 1;
	for (int i = 1; i <= o; i++) {
		cnt *= 2;
	}
	return cnt;
}

int ff(int x) {
	long long cnt = 0;
	for (int i = 1; i <= 32; i++) {
		cnt += b[x][i] * poww(i - 1);
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f(a[i], i);
	}
	int cnttt = n;
	for (int i = 32; i >= 1; i--) {
		int cnt = 0, cntt = 0;
		for (int j = 1; j <= cnttt; j++) {
			if (b[j][i] == 1) {
				cnt++;
			}
		}
		if (cnt >= m) {
			for (int j = 1; j <= cnttt; j++) {
				if (b[j][i] == 1) {
					++cntt;
					for (int k = 1; k <= 32; k++) {
						e[cntt][k] = b[j][k];
					}
				}
			}
			cnttt = cntt;
			for (int j = 1; j <= cnttt; j++) {
				for (int k = 1; k <= 32; k++) {
					b[j][k] = e[j][k];
				}
			}
		}
	}
	ans = ff(1);
	for (int i = 2; i <= m; i++) {
		long long o = ff(i);
		ans &= o;
	}
	cout << ans;
	return 0;
}