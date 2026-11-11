#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 2e6;
int c, t, x[N + 5];
signed main(){
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t --){
		int n, d;
		cin >> n >> d;
		bool flag = 1;
		int tot;
		memset (x, 0, sizeof x);
		for (int i = 1; i <= n; ++ i){
			cin >> x[i];
			if (i == 2) tot = x[2] - x[1];
			if (i > 1 && tot != x[i] - x[i - 1]) flag = 0;
		}
		if (flag){
			if ((d % tot != 0 && d % tot != 1) || d <= tot){
				cout << "0\n";
				continue;
			}
			if (d / tot >= n) cout << "0\n";
			else cout << n - d / tot * 2 + 1 << "\n";
			return 0;
		}
		if (x[n] - x[1] <= d){
			cout << "0\n";
		}
	}
	return 0;
}
/*
 0 2
 4 2
 1 2 3 4
 5 2
 1 2 3 4 5
*/
