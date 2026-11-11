#include <bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> c[i];
	}
	int l = 1, r = n;
	long long ans = 0;
	while (l != r && l < r) {
		if (c[l] == c[r]) {
			if (a[l] < a[r]) {
				a[r] = a[r] - a[l];
				l++;
				continue;
			}
			if (a[r] > a[l]) {
				a[l] = a[l] - a[r];
				r--;
				continue;
			}
			if (a[r] == a[l]) {
				l++;
				r--;
				continue;
			}
		} else {
			if (a[l] < a[r]) {
				ans += a[l];
				a[r] = a[r] - a[l];
				l++;
				continue;
			}
			if (a[r] < a[l]) {
				ans += a[r];
				a[l] = a[l] - a[r];
				r--;
				continue;
			}
			if (a[r] == a[l]) {
				ans += a[r];
				r--;
				l++;
				continue;
			}
		}
	}
	cout << ans;
	return 0;
}