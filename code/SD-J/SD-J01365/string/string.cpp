#include <bits/stdc++.h>
#define int long long
using namespace std;
const unsigned long long rp = 2e18;
int n,a[200010],c[200010],ans;
char cc;
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> cc;
		c[i] = cc - 'a';
	}
	int l = 1,r = n;
	while (l < r) {
//		printf("?%lld,%lld|%lld,%lld|%lld\n",l,a[l],r,a[r],ans);
		int x = min(a[l],a[r]);
		if (c[l] != c[r]) ans += x;
		if (a[l] < a[r]) a[r] -= x,++l;
		else if (a[l] > a[r]) a[l] -= x,--r;
		else if (a[l] == a[r]) ++l,--r;
//		printf("!%lld,%lld|%lld,%lld|%lld\n",l,a[l],r,a[r],ans);
	}
	cout << ans;
	return 0;
}

