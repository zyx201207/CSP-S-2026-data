#include<bits/stdc++.h>
using namespace std;
const int N = 3 + 5e5;
int n, ans = 1;
long long m, a[N], b[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		b[i - 1] = a[i] - a[i - 1];
	}
	int xyz = 0;
	for (int i = 1; i < n; i++) {
		if (b[i] == b[i + 1]) {
			xyz++;
		}
	}
	if (xyz != n - 1) {
		for (int k = n; k >= 1; k--) {
			int i = 1, sum = 1;
			long long zxc = m;
			while (zxc > 0) {
				long long qwq = a[k] - a[k - i];
				if (k - i <= 0) {
					break;
				}
				if (zxc - qwq >= 0) {
					sum++;
					zxc -= qwq;
				} else {
					break;
				}
				i++;
			}
			ans = max(ans, sum);
		}
	} else {
		long long asd = a[2] - a[1], i = 1;
		while (m > 0) {
			long long zxc = asd*i;
			if (m - zxc >= 0) {
				ans++;
				m -= zxc;
			} else {
				break;
			}
			i++;
		}
	}
	cout << ans;
	return 0;
}