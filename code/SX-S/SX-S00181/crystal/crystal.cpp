#include <bits/stdc++.h>
using namespace std;

bool cmp(long long x, long long y) {
	return x < y;
}
long long n, m, a[500005], b[500005],  x, y, cnt, sum_l, sum_r, cnt1, cnt2 = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		x = i;
		y = i;
		cnt = 0;
		cnt1 = 0;
		if (i != 1) {
			for (int j = 1; j <= n; j++) {
				a[j] = b[j];
			}
		}
		while (cnt <= m) {
			cnt1 += 1;
			sum_r = 0;
			if (!(x - 1 <= 0))
				sum_l = sum_l + a[y] - a[x - 1];
			else
				sum_l = 10000000005;
			if (!(y == n)) {
				for (int s = x; s <= y; s++) {
					sum_r += a[y + 1] - a[s];
				}
			} else
				sum_r = 10000000005;
			if (sum_l <= sum_r) {
				if (cnt + sum_l <= m) {
					x--;
					cnt += sum_l;
					a[x] = a[y];
				} else
					break;
			} else {
				if (cnt + sum_r <= m) {
					y++;
					cnt += sum_r;
					for (int s = x; s <= y; s++) {
						a[s] = a[y];
					}
				} else
					break;
			}
		}
		if (cnt1 == 10000000005) {
			cnt1 = 1;
		}
		cnt2 = max(cnt2, cnt1);
	}
	cout << cnt2;
}