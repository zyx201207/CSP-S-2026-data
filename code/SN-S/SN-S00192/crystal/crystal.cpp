#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[500005],sa[500005],ssa[500005];

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	sa[n] = 0;
	for (int i = n - 1;i >= 1;i--) {
		sa[i] = sa[i + 1] + a[i + 1] - a[i];
	}
	for (int i = 1;i <= n;i++) {
		ssa[i] = ssa[i - 1] + sa[i];
	}
	for (int i = 2;i <= n;i++) {
		if (m - ssa[i - 1] + sa[i] * (i - 1) < 0) {
			cout << i - 1 << "\n";
			return 0;
		}
	}
	cout << n << "\n";
	return 0;
}
