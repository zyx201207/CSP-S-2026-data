#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
ll c, T, n, k, u[N], v[N];
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while(T--) {
		cin >> n >> k;
		for(int i = 1; i <= n; i++) {
			cin >> u[i] >> v[i];
		}
		ll m = n / 2, ans;
		if(n == k) {
			ans = 0;
		}
		else {
			ans = (m - k + 3) / 4 + 1;
		}
		cout << ans << endl;
	}
	return 0;
}
