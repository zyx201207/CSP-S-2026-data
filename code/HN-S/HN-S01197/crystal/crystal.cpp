#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 5;

int n, m, ans = 1, s = 0, a[N];

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 2, l = 1; i <= n; ++i){
		s += (i - l) * (a[i] - a[i - 1]);
		for(; l <= i && s > m; l++){
			s -= a[i] - a[l];
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}
