#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10086;

struct Str {
	int n;
	char c;
} a[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].n >> a[i].c;
		sum += a[i].n;
	}
	int l = 1, r = n + 1, suml = 0, sumr = 0, ans = 0;
	while (l < r) {
		suml += a[l].n;
		while (r > l && sumr + a[r - 1].n <= suml) {
			sumr += a[--r].n;
			if (a[l].c != a[r].c) ans += a[r].n;
		}
		if (sumr < suml && l + 1 < r) {
			a[r - 1].n -= suml - sumr;
			if (a[r - 1].c != a[l].c) ans += suml - sumr;
			sumr = suml;
		} // suml = sumr
		l++;
	} 
	cout << ans;
	return 0;
}