#include <bits/stdc++.h>
using namespace std;

int a[200010], b[200010];
long long dx[200010];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, maxx = INT_MIN;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
		a[i] = 0;
		while (b[i] > 0) {
			a[i] += b[i] % 2;
			b[i] /= 2;
			if (b[i] != 0) {
				a[i] *= 10;
			}
		}
	}
	dx[1] = a[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i - 1; j++) {
			if (a[i] < dx[j] && a[i] >= dx[j + 1]) {
				for (int k = i - 1; k >= j + 2; k++) {
					dx[k] = dx[k - 1];
				}
				dx[j + 1] = a[i];
			}
		}
	}
	for (int i = 1; i <= n - m; i++) {
		int and_sum = 1111111111;
		for (int j = i; j <= i + m - 1; i++) {
			and_sum = and_sum && dx[i];
		}
		if (dx[i] && dx[i + 1] > maxx) {
			maxx = dx[i] && dx[i + 1];
		}
	}
	int p = maxx, cnt = 0;
	maxx = 0;
	while (p > 0) {
		int cf = 1;
		for (int i = 1; i <= cnt; i++) {
			cf *= 2;
		}
		maxx += cf * (p % 10);
		p /= 10;
		cnt++;
	}
	cout << maxx;
	return 0;
}