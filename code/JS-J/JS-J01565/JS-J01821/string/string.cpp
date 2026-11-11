# include <bits/stdc++.h>
# define int long long
using namespace std;
const int N = 2e5 + 5;
int n,l,r,sum_l,sum_r,ans,a[N],b[N]; char x[N],y[N];
signed main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n; l = r = 1;
	for (int i = 1;i <= n;i++) cin >> a[i] >> x[i],b[n - i + 1] = a[i],y[n - i + 1] = x[i];
	while (l <= n) {
		if (sum_l < sum_r) {
			if (x[l] != y[r - 1]) ans += min(sum_l + a[l],sum_r) - sum_l;
			sum_l += a[l]; l ++;
		}
		while (r <= n && sum_r <= sum_l) {
			if (x[l - 1] != y[r]) ans += min(sum_l,sum_r + b[r]) - sum_r;
			sum_r += b[r]; r ++;
		}
	}
	cout << ans / 2;
    return 0;
}
