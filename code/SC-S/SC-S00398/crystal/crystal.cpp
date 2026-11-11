#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m;
int a[N], pv[N];
int result(int l, int r) {
	return (pv[r] - pv[l]) - (l - 1) * (a[r] - a[l]);
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i ++) {
		pv[i] = pv[i-1] + (i - 1) * (a[i] - a[i-1]);
	}
	int l = 1, r = 1, ans = -1;
	while (r <= n) {
		int w = result(l, r);
		if (w <= m) {
			ans = max(ans, r - l + 1);
			r ++;
		} else l ++;
	}
	cout << ans;
	return 0;
}