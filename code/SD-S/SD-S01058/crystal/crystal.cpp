#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
/*====================*/
const int N = 5e5 + 10;
int a[N], cha[N];
int n, m;
/*====================*/
bool check1(int x) {
	int tot = LLONG_MAX;
	for (int i = x; i <= n; i++) {
		tot = min(tot, (x - 1) * (cha[i] * x - 2 * cha[i] + 2) / 2);
	}
	return tot <= m;
}
/*====================*/
bool check2(int x) {
	int tot = LLONG_MAX;
	for (int i = x; i <= n; i++) {
		int res = 0;
//		for (int j = i; j >= i - x + 2; j--) {
//			res += cha[j] * (j - i + 2 + x);  //j - i + 2
//		}
		for (int j = 2; j <= x; j++) {
			res += cha[i - x + j] * (j - 1);
		}
		tot = min(tot, res);
	}
	return tot <= m;
}
/*====================*/
void Solve() {
	cin >> n >> m;
	int minn = LLONG_MAX, maxn = -LLONG_MAX;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		minn = min(minn, a[i]);
		maxn = max(maxn, a[i]); 
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		cha[i] = a[i] - a[i - 1];
	}
	bool flag = true;
	for (int i = 3; i <= n; i++) {
		if (cha[i] != cha[i - 1]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		int l = 1, r = n, ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (check1(mid)) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		cout << ans << endl;
	}
	else {
		int l = 1, r = n, ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (check2(mid)) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		cout << ans << endl;
	}
	return;
}
/*====================*/
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	Solve();
	return 0;
} 

/*
5 8
-3 -1 2 2 7

*/
