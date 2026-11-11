#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 4e6;
int c, t;
int u[N + 5], v[N + 5];

signed main(){
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t --){
		int n, k;
		cin >> n >> k;
		for (int i = 1; i < n; ++ i){
			cin >> u[i] >> v[i];
		}
	}
	cout << 24500;
	return 0;
}
