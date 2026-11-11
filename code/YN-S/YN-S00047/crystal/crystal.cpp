#include <bits/stdc++.h>
using namespace std;
long long a[500010], s[500010], L[200010];
long long n, m;

int cp(int x) {
	int i = x;
	while (L[i + 100000] == 0) {
		i--;
	}
	return L[i + 100000]  * x - s[L[i + 100000]];
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		L[a[i] + 100000] = i;
		s[i] = s[i - 1] + a[i];
	}
	int l = a[1], r = a[n];
	while (l < r) {
		int mid = (l + r) / 2;
		if (cp(mid) > m) {
			r = mid;
		} else {
			l = mid + 1;
		}
//		cout << cp(mid) << endl;
	}
	int ans = 0;
	for (int i = 1; i <= n && a[i] <= l - 1; i++) {
		ans++;
	}
	cout << ans ;
	return 0;
}