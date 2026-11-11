#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6 + 5;
int c, t, n, d, ans;
int a[N];

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for (int i = 1; i <= n; i++)cin >> a[i];
		int c = a[2] - a[1];
		for (int i = 1; i < n - c; i++){
			ans += (a[n] - a[i] - d + c) / d;
		}
		cout << ans << '\n';
		ans = 0;
	}
	return 0;
}
		
