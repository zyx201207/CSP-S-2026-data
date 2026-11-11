#include <bits/stdc++.h>
using namespace std;

int a[500005];
int n[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, num = 0, f = 1, wz;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			for (int k = 1; k <= num; k++) {
				if (a[j] == n[k]) {
					f = 0;
					wz = k;

				}
			}
			if (f == 1) {
				n[num] = a[j];
				nun++;
			} else {
				for (int k = wz; k <= num; k++) {
					n[k] = 0;
					num -= (num - wx);
				}
				f = 1;
				num++;
				n[num] = a[j];
			}
		}
		for (int j = 1; j <= num; j++) {
			if (n[j] == i) {
				int ans = 0;
				ans++;
			}
		}
		cout << ans << ' ';
		for (int j = 1; j <= num; j++) {
			n[j] = 0;
			ans = 0;
			f = 1;
		}
	}
	return 0;
}