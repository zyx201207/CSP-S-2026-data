# include <bits/stdc++.h>
# define int long long
using namespace std;
const int N = 5e5 + 5;
int n,m,l,r,sum,len,ans,a[N];
signed main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m; l = r = 0; len = ans = 1;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	while (l <= n) {
		sum -= a[r] - a[l ++]; len --;
		while (r < n && (sum + len * (a[r + 1] - a[r])) <= m) sum += len * (a[r + 1] - a[r]),len ++,r ++;
		ans = max(ans,len);
	}
	cout << ans;
	return 0;
}
