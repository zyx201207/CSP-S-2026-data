#include<bits/stdc++.h>//100
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
int n;
ll m, a[N];
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll sum = 0;
	int ans = 0; 
	for (int l = 1, r = 1; l <= n; ++ l) {
		while (r < n && sum <= m) {
			r ++;
			sum += (1ll * (r - l)) * (a[r] - a[r - 1]);
		}	
		sum -= (a[r] - a[l]);
		ans = max(ans, (r - 1) - l + 1);
	}
	cout << ans;
	return 0;
} 
