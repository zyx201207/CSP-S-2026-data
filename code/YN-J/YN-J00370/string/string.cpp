#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], l, r, num[200005], ans;
char x[200005], c[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> x[i];
		a[i] = a[i - 1] + a[i];
	}
	long long mid = (a[n] + 1) / 2, flag = 0, end = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i - 1] < mid && a[i] > mid) {
			num[i] = mid - a[i - 1];
			num[i + 1] = a[i] - mid;
			c[i] = x[i];
			c[i + 1] = x[i];
			flag = 1;
			end = i;
			continue;
		}
		num[i + flag] = a[i] - a[i - 1];
		c[i + flag] = x[i];
	}
	n += flag;
	l = 1;
	r = n;
	while (l <= end && r > end) {
		if (num[l] > num[r]) {
			if (c[l] != c[r])
				ans += num[l] - num[r];
			num[l] -= num[r];
			r--;
		} else if (num[l] < num[r]) {
			if (c[l] != c[r])
				ans += num[r] - num[l];
			num[r] -= num[l];
			l++;
		} else {
			if (c[l] != c[r])
				ans += num[l];
			l++;
			r--;
		}
	}
	cout << ans;
	return 0;
}