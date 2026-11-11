#include <bits/stdc++.h>
#define int long long
using namespace std;
const unsigned long long rp = 2e18;
int n,m,a[200010],ans;
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	bool flgb = (n & -n) == n,flga = 1,flga4 = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] != i - 1) flgb = 0;
		int x = a[i] + 1;
		if ((x & -x) != x) flga = 0;
		if (a[i] >= 4) flga4 = 0;
	}
	if (flga) {
		sort(a + 1,a + 1 + n,greater<int>());
		cout << a[m];
	} else if (flgb) {
		int cnt = (1ll << 31) - 1;
		for (int j = n; j >= n - m + 1; --j) cnt &= a[j];
		cout << cnt;
	} else if (flga4) {
		int x[4] = {0,0,0,0};
		for (int i = 1; i <= n; ++i) ++x[a[i]];
		if (x[3] >= m) cout << 3;
		else if(x[3] + x[2] >= m) cout << 2;
		else if (x[3] + x[1] >= m) cout << 1;
		else cout << 0;
	} else {
		sort(a + 1,a + 1 + n,greater<int>());
		for (int i = 1; i + m - 1 <= n; ++i) {
			int cnt = (1ll << 31) - 1;
			for (int j = i; j <= i + m - 1; ++j) cnt &= a[j];
			ans = max(ans,cnt);
		}
		cout << ans;
	}
	return 0;
}

