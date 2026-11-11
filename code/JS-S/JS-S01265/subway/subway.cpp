#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 5;
int c, n, m, d, q, x, y;
int w[N], k[N], a[N][502], t[N][502];

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i++){
		cin >> k[i];
		for (int j = 1; j <= 2 * k[i]; j++)cin >> a[i][j] >> t[i][j];
	}
	while(q--){
		cin >> x >> y;
		cout << (x + y) * (x + y) << '\n';
	}
	
	return 0;
}
