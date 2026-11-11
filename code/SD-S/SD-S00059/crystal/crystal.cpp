/*
crystal
*/
#include <bits/stdc++.h>
#define ll long long
#define N 500010
#define INF 1e9
using namespace std;
ll n, m, a[N];
ll pre[N];
ll ans[N];
int res;
void go() {
	ll cha = abs(a[2] - a[1]);
	ll ned = m / cha;
	int now = 0;
	for (ll i = 1; 1; ++i) {
		now = now + i;
		if (now > ned) {
			cout << i;
			return;
		}
	}
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int cha = a[2] - a[1];
	bool A_B = true;
	for (int i = 2; i <= n; ++i) {
		if (a[i] - a[i - 1] != cha) {
			A_B = false;
		}
	}
	if (A_B) {
		go();
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1] + a[i];
		ans[i] = a[i] * (i - 1) - pre[i - 1];
		if (ans[i] <= m) {
			res = max(res, i);
		}
	}
	ll now = res;
	for (int i = now + 1; i <= n; ++i) { // 枚举 i 
		int l = 2, r = n, mid;           // 二分查找 l 
		while (l < r) {
			mid = (r - l) / 2 + l;
			ll now = (i - mid) * a[i] - pre[i - 1] + pre[mid - 1];
			if (now <= m) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		res = max(res, i - l + 1);
	}
	cout << res;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/

/*
5 1000000000004
-1000000000000 1000000000000 0 -1 1

4
*/
