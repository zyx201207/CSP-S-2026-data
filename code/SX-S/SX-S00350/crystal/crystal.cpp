#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+10;
ll n, m, a[N], cha[N], ans;
//实际求m次操作后能有几个相同能量值的水晶；
//cha[i] 第i-1和第i个差值 第i-2和i差值为 cha[i-1]+cha[i]
//isA isB
ll need[N], cst;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	bool isA = true, isB = true;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		cha[i] = a[i] - a[i - 1];
		if (i == 2)
			cst = a[2] - a[1];
		if (a[i] != i) {
			isA = false;
		}
		if (a[i] - a[i - 1] != cst && i != 1) {
			isB = false;
		}
	}
	if (isA) {
		for (int i = 1; i <= n; i++) {
			need[i] = need[i - 1] + i - 1;
			if (m >= need[i - 1] && m < need[i]) {
				cout << i - 1;
				return 0;
			}
		}

	} else if (isB) {
		for (int i = 1; i <= n; i++) {
			need[i] = need[i - 1] + cst * (i - 1);
			if (m >= need[i - 1] && m < need[i]) {
				cout << i - 1;
				return 0;
			}
		}
	}
	sort(a + 1, a + 1 + n);
	ll cnt = 0;
	for (ll i = n; i >= 1; i--) {
		cnt = 0;
		bool flag = true;
		for (ll j = i ; j >= 1; j--) {
			cnt += a[i] - a[j];
//			cout << cnt << ' ' << j << ' ' << i << endl;
			if (cnt > m) {
				ans = max(i - j, ans);
				flag = false;
				break;
			}
		}
		if (flag) {
			ans = max(i, ans);
		}
	}
	cout << ans;
	return 0;
}