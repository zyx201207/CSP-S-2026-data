#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, d, a[2 * (int)1e6];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		cout << (n - 1) * (n - 2) / 2 << endl;
	}
	return 0;
}