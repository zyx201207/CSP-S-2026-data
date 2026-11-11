#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[2000010];
int b[2000010];
int num = 1;
int sum;
int ans = 0;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	if (n <= 5000) {
		for (int i = 2; i <= n; i++) {
			sum = 0;
			num = 1;
			for (int j = i; j <= n; j++) {
				if (sum + (a[j] - a[j - 1]) * num <= m) {
					sum += (a[j] - a[j - 1]) * num;
					num++;
				}
			}
			ans = max(ans, num);
		}
		cout << ans;
	} else {
		for (int i = 2; i <= n; i++) {
			if (sum + (a[i] - a[i - 1]) * num <= m) {
				sum += (a[i] - a[i - 1]) * num;
				num++;
			}
		}
		cout << num;
	}
	return 0;
}
