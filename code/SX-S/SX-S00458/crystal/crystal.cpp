#include <bits/stdc++.h>
using namespace std;
const int N = 50005;
int n, m, a[N], sum, ss = 1e9, k, ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = a[1]; i <= a[n]; i++) {
		sum = 0;
		for (int j = 1; j <= n; j++) {
			if (a[j] >= i)
				sum += a[j] - i;
			else
				sum += i - a[j];
		}
		if (ss > sum) {
			ss = sum;
			k = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == k) {
			ans++;
			int l = i - 1, r = i + 1;
			while (m > 0) {
				if (k - a[l] >= a[r] - k && r <= n) {
					if (m >= a[r] - k) {
						ans++;
						r++;
					}
					m -= (a[r - 1] - k);
				} else {
					if (m >= k - a[l] && l >= 1) {
						ans++;
						l--;
					}
					m -= (k - a[l + 1]);
				}
			}
			break;
		} else if (a[i] < k && a[i + 1] > k) {
			int l = i, r = i + 1;
			while (m > 0) {
				if (k - a[l] >= a[r] - k && r <= n) {
					if (m >= a[r] - k) {
						ans++;
						r++;
					}
					m -= (a[r - 1] - k);
				} else if (k - a[l] < a[r] - k) {
					if (m >= k - a[l] && l >= 1) {
						ans++;
						l--;
					}
					m -= (k - a[l + 1]);
				}
			}
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}