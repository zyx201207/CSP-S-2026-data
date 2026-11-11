#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], k, f[200005], ans;
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m, k = 1 << 29;
	for (int i = 1; i <= n; i++) cin >> a[i]; 
	for (int i = 1 << 29; i; i >>= 1){
		int cnt = 0; 
		for (int j = 1; j <= n; j++) if (a[j] & i && !f[j]) cnt++;
		if (cnt < m) continue;
		else{
			for (int j = 1; j <= n; j++) if (!(a[j] & i)) f[j] = 1;
			ans += i;
		}
	}cout << ans;
	return 0;
}
