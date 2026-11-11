#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005], sum, ans, l = 1, r;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m, r = n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 2, j = 0; i <= n; i++){
		sum += (i - j - 1) * (a[i] - a[i - 1]);
		while (sum > m) sum -= a[i] - a[j], j++;
		ans = max(ans, i - j);
	}cout << ans;
	return 0;
}

