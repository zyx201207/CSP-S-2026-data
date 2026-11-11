#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
int n, a[N];
char c[N];
int ans;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	int li = a[1], lj = a[n];
	for (int i = 1, j = n; i < j; ) {
		if (c[i] != c[j]) {
			if (li < lj) {
				ans += li;
				lj -= li;
				li = a[++i];
			} else {
				ans += lj;
				li -= lj;
				lj = a[--j];
			}
		} else {
			if (li < lj) {
				lj -= li;
				li = a[++i];
			} else {
				li -= lj;
				lj = a[--j];
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
