#include<bits/stdc++.h>
#define ll long long
#define ull long long unsigned
using namespace std;
const int N = 5e5 + 5;
int n;
ull m;
ll a[N];
int check(int cnt) {
	ull ans = 0, min_ans = 1e18+1;
	for(int i = 1; i < cnt; ++i) {
		ans += a[cnt] - a[i];
	}
	min_ans = ans;
	for(int l = 1, r = cnt; r+1 <= n; ++l, ++r) {//[l+1, r+1]
		ans += (a[r+1] - a[r]) * cnt;
		ans -= a[r+1] - a[l];
		min_ans = min(min_ans, ans);
//		cout << l+1 << ' ' << r+1 << ' ' << ans << '\n';
	}
	return min_ans <= m;
}
int work() {
	int l = 1, r = n, mid = 0;
	while(l + 1 < r) {
		mid = (l&r) + ( (l^r) >> 1);
//		cout << mid << '\n';
		if(check(mid) ) {
			l = mid;
		} else r = mid - 1;
	}
	return l;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	cout << work();
	return 0;
}
