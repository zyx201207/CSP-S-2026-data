#include <bits/stdc++.h>
#define int long long
using namespace std;

int t,n,m,a[500005],b[200005],sa[200005],l2 = 1,ans;

signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	做完要得双鸟失群症了，谁懂刚做完然后老师说是双向边,重做力（悲），而且最终代码好像还假了
	cin >> t >> t;
	while (t--) {
		cin >> n >> m;
		if (m == 1) {
			cout << "0\n";
			continue;
		}
		sa[0] = ans = 0;
		for (int i = 1;i <= n;i++) {
			cin >> a[i];
			sa[i] = sa[i - 1] + a[i] - a[i - 1];
			while (sa[i] - sa[l2] > 2 * m) l2++;
			if (i >= 4) {
				if ((i - l2 + 1) % 2 == 0)
					ans += max(0ll,sa[i] - l2 - 2);
			}
//			cout << "sa[i]:" << sa[i] << " l2:" << l2 << " ans:" << sa[i] - l2 - 2 << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}

