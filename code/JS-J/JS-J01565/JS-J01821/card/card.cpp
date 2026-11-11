# include <bits/stdc++.h>
# define int long long
using namespace std;
const int N = 5e5 + 5;
int n,m,p,a[N],b[N],lst[N],ans[N],vis[N];
signed main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = n;i >= 1;i--) b[i] = lst[a[i]],lst[a[i]] = i;
	for (int i = 1;i <= n;i++) {
		p = i;
		while (p <= n) {
			vis[a[p]] = 1;
			if (b[p] != 0) p = b[p];
			else p ++;
		}
		for (int j = 1;j <= m;j++) ans[j] += vis[j],vis[j] = 0;
	}
	for (int i = 1;i <= m;i++) cout << ans[i] << ' ';
    return 0;
}
