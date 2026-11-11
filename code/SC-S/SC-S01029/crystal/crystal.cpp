#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int n, m, a[N], s[N], mx;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int l = n - 1, r = n;
	long long s = a[r] - a[l];
	while (l > 0 && r > 0) {
		if (s > m) {
			mx = max(mx, r - l);
			while (s > m && r > l) {
				s = s - (r - l) * 1ll * a[r] + (r - l) * 1ll * a[r - 1];
				r--;
			}
		} else l--, s += a[r] - a[l];
	}
	mx = max(mx, r - max(1, l) + 1);
	printf("%d", mx);
	return 0;
}
