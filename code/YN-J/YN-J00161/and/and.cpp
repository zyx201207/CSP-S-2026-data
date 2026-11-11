#include <bits/stdc++.h>
using namespace std;
long long m, n;
long long ans;
long long a[200005], b[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int i = 3, cnt = 2;
	ans = a[1] & a[2];
	while (i < n) {
		if (ans < a[i]&a[i + 1]&ans && cnt <= m) {
			cnt++;
			ans = a[i] & a[i + 1] & ans;
		}
		ans = max(ans, a[i] & a[i + 1]);
		i++;
	}
	cout << ans;
	return 0;
}