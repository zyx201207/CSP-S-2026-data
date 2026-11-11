#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005],ans = -1;
bool cmp(long long x, long long y) {
	return x > y;
}
bool check( long long num) {
	bool flag = true;
	long long cnt = m, cntans = 0;
	for ( long long i = 1; i <=n; i++) {
		if (num == a[i]) cntans++;
		if (num > a[i]) {
			if (cnt >= (num - a[i])) {
				cnt -= (num - a[i]);
				cntans++;
			} else 
				flag = false;
		}
	}
	if (cntans > ans) {
		ans = cntans;
	}
	if (flag == 1) return true;
	else return false;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for ( long long i = 1; i <= n ; i++) 
		cin >> a[i];
	sort(a + 1, a + 1 + n, cmp); 
	long long l = -2e12, r =2e12, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)){
			l = mid+1; 
		}
		else
			r = mid-1;
	}
	cout << ans;
	return 0;
}