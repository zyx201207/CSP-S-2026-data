#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], tmp, ans = 1, sum;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	tmp = 1;
	for(int i = 2; i <= n; i ++) {
		sum += (i - tmp) * (a[i] - a[i - 1]);
		while(sum > m) {
			sum -= a[i] - a[tmp];
			tmp ++;
		}
		ans = max(ans, i - tmp + 1);
	}
	cout << ans;
	return 0;
}