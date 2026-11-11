#include <bits/stdc++.h>
using ll = long long; using ull = unsigned long long;
const int MAXN = 1e6 + 10;
const int INF32 = INT_MAX; const ll INF64 = LLONG_MAX;
using namespace std;
ll n, m;
ll a[MAXN], sum[MAXN];
ll chk(ll L, ll R) {
//	cout << (R - L) << " " << a[R] << " " << (sum[R - 1] - sum[L - 1]) << endl;
	return (R - L) * a[R] - (sum[R - 1] - sum[L - 1]);
} 
int fd(int r) {
	int l = 1, R = r;// I am an idot! 
	while (l < r) {
		int mid = (l + r) >> 1;
//		cout << mid << ' ';
		if (chk(mid, R) <= m) r = mid;
		else l = mid + 1;
	}
//	cout << endl;
	return l;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
//		cout << sum[i] << ' ';
	} 
//	return 0;
	
//	cout << chk(2, 4);
//	return 0;
	// 高度单调递增
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int pos = fd(i);
//		cout << '#' << pos << endl;
		ans = max(ans, i - pos + 1);
	} 
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9
ans = 3

5 8
-3 -1 2 2 7
ans = 4

5 1
1 2 3 4 5
ans = 2
*/
