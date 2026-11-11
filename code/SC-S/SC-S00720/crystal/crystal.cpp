#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005];
long long st = 0;
long long ans = 1, f = 0;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	st = (n - 1) / 2;
	f = a[st];
	long long r = st + 1, l = st - 1;
	while (m > 0) {
		if (a[r] == f && r < n - 1) {
			r++;
			ans++;
			continue;
		}
		if (a[l] == f && l > 0) {
			l--;
			ans++;
			continue;
		}
		if (r >= n + 1 && l <= -1) break;
		if (a[r] - a[st] < a[st] - a[l] && a[r] - a[st] <= m) {
			m -= a[r] - a[st];
			ans++;
			if (r < n - 1)r++;
		} else if (a[r] - a[st] > a[st] - a[l] && a[st] - a[l] <= m) {
			m -= a[st] - a[l];
			ans++;
			if (l > 0)l--;
		} else if (a[r] - a[st] == a[st] - a[l] && a[st] - a[l] <= m) {
			m -= a[r] - a[st];
			ans++;
			if (r < n - 1)r++;
		} else break;
		//cout << a[l] << " " << a[r] << endl;
		//cout << m << endl;
	}
	cout << ans;
	return 0;
}