#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
ll n, m, l = 1e18, r = -1e18, num, a[N], ans;
bool check(ll x) {
	ll sum = 0;
	num = 0;
	for (int i = 1; i <= n; i ++) {
		sum += (x-a[i] >= 0 ? x-a[i] : 0);
		if (x - a[i] >= 0) num ++;
	}
	return sum <= m; 
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		l = min(l, a[i]);
		r = max(r, a[i]);
	}
	while (l <= r) {
		ll mid = l + (r - l) / 2;
		if (check(mid)) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << num << "\n";
	return 0;
}