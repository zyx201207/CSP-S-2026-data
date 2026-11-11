#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 5e5+5;
int n, m, ans, a[N];
signed main(){
	freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
	cin >> n >> m; for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int l = 1, r = 1, cst = 0; r <= n; r++){
		cst += (r-l)*(a[r]-a[r-1]);
		while (cst > m) l++, cst -= (a[r]-a[l]);
		ans = max(ans, r-l+1);
	} cout << ans;
	return 0;
}
