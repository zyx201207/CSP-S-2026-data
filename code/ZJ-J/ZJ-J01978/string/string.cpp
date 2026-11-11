#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200010]; char c[200010];

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("string.in", "r", stdin); freopen("string.out", "w", stdout);
	cin >> n;
	int sum = 0;
	for (int i = 1;i <= n;i++) {
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	int l = 1, r = n, c1 = a[1], c2 = a[n], suml = 0, sumr = 0;
	int ans = 0;
	while (suml + sumr <= sum) {
		if (min(c1, c2) * 2 + suml + sumr > sum) break;
		if (c[l] != c[r]) ans += min(c1, c2);
		if (c1 < c2) {
			c2 -= c1; suml += c1; sumr += c1;
			c1 = a[++l];
		} else if (c1 > c2) {
			c1 -= c2; suml += c2; sumr += c2;
			c2 = a[--r];
		} else {
			c1 = a[++l]; suml += c2; sumr += c2;
			c2 = a[--r];
		}
		//cerr << l << " " << r << " " << c1 << " " << c2 << "\n";
	}
	cout << ans;
	return 0;
}
