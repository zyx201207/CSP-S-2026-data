#include <bits/stdc++.h>
using namespace std;
#define ll long long
int const N = 5e5 + 10;
ll q[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	ll n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> q[i];
	}
	sort(q + 1, q + n + 1);
	//ÆæÊý
	ll zwsid;
	ll min1 = INT_MAX, suml = 0, sumr = 0, xt = 0;
	if (n % 2 == 1) {
		zwsid = n / 2 + 1;
		for (int i = 1; i <= n; i++) {
			if (q[i] == q[zwsid] && i != zwsid) {
				xt++;
			}
		}
		for (int i = 1; i <= zwsid; i++) {
			suml += q[zwsid] - q[i];
		}
		for (int i = zwsid + 1; i <= n; i++) {
			sumr += q[i] - q[zwsid];
		}
		if (suml <= m && sumr >= suml) {
			cout << zwsid + xt;
		} else {
			cout << n - zwsid + xt + 1;
		}
	}
	//Å¼Êý
	if (n % 2 == 0) {
		suml = 0, sumr = 0;
		int ans1, ans2;
		zwsid = n / 2;
		int min2 = INT_MAX, id;
		for (int i = 1; i <= zwsid; i++) {
			int dis = q[zwsid] - q[i];
			if (min2 > dis) {
				min2 = dis;
				id = i;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (q[i] == q[zwsid] && i != zwsid) {
				xt++;
			}
		}
		for (int i = 1; i <= zwsid; i++) {
			suml += q[zwsid] - q[i];
		}
		for (int i = zwsid + 1; i <= n; i++) {
			sumr += q[i] - q[zwsid];
		}
		if (suml <= m && sumr >= suml) {
			ans1 = zwsid + xt;
		} else {
			ans1 = n - zwsid + xt + 1;
		}
		zwsid = n / 2 + 1;
		int min3 = INT_MAX, id1;
		for (int i = zwsid + 1; i <= n; i++) {
			int dis = q[i] - q[zwsid];
			if (min3 > dis) {
				min3 = dis;
				id1 = i;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (q[i] == q[zwsid] && i != zwsid) {
				xt++;
			}
		}
		for (int i = 1; i <= zwsid; i++) {
			suml += q[zwsid] - q[i];
		}
		for (int i = zwsid + 1; i <= n; i++) {
			sumr += q[i] - q[zwsid];
		}
		if (suml <= m && sumr >= suml) {
			ans2 = zwsid + xt;
		} else {
			ans2 = n - zwsid + xt + 1;
		}
		if (ans1 > ans2 && ans1 <= m) {
			cout << ans1;
		} else {
			cout << ans2;
		}
//		int ans, ansid;
//		if (min2 > min3) {
//			ans = min3;
//			ansid = id1;
//		} else {
//			ans = min2;
//			ansid = id;
//		}
//		int c = m / ans;
//		if (m % ans != 0) {
//			for (int i = 1; i <= n; i++) {
//				if (q[i] + (m % ans) == q[ansid]) {
//					c++;
//					break;
//				}
//			}
//		}
//		cout << c;
	}
	return 0;
}