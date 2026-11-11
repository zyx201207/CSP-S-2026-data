#include <bits/stdc++.h>
#define ll long long
#define rep(a, b, c) for (int i = a; i <= b; i += c)
const int MAXN = 5e5 + 5;
using namespace std;
ll n, m, ans, st = 1, d, a[MAXN], qzh[MAXN];
bool flag = 1;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	if (n >= 2) {
		cin >> a[1] >> a[2];
		d = a[2] - a[1];
		st = 3;
	}
	rep(st, n, 1) {
		cin >> a[i];
		if (a[i] - d != a[i - 1]) flag = 0;
	}
	sort(a + 1, a + 1 + n);
	rep(1, n, 1) qzh[i] = qzh[i - 1] + a[i];
	if (flag) {
		rep(1, n, 1) {
			ans = i;
			if ((qzh[i] - i * qzh[1]) > m) {
				ans = i - 1;
				break;
			}
		}
		cout << ans << '\n';
		return 0;
	} 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if ((qzh[i] - qzh[j - 1]) + m >= a[i] * (i - j + 1)) {
				ans = max(ans, (long long)(i - j + 1));
				break;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
/*
#include <bits/stdc++.h>
#define ll long long
#define rep(a, b, c) for (int i = a; i <= b; i += c)
const int MAXN = 5e5 + 5;
using namespace std;
ll n, m, l, r, ans1 = LLONG_MIN, ans2 = LLONG_MIN, a[MAXN], qzh[MAXN];

int check(int i, int m) {
	ll ans = LLONG_MIN;
	for (int j = 1; j <= i; j++) {
//		cout << i << ' ' << j << endl;
		if ((qzh[i] - qzh[j - 1]) + m >= a[i] * (i - j + 1)) {
			ans = max(ans, (long long)(i - j + 1));
			break;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("crystal.spec", "r", stdin);
//	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	rep(1, n, 1) cin >> a[i];
	sort(a + 1, a + 1 + n);
	rep(1, n, 1) qzh[i] = qzh[i - 1] + a[i];
	l = 1 , r = n;
//	cout << l << ' ' << r << endl;
//	rep(1, n, 1) cout << a[i] << ' ';
//	cout << '\n';
	while (l < r) {
		int mid = (l + r) / 2, p = check(mid, m);
//		printf("[%lld, %lld]: mid = %d, p = %d, nowans = %d\n", l, r, mid, p, ans1);
		if (p > ans1) l = mid + 1, ans1 = p;
		else r = mid;
	}
	l = 1, r = n;
	while (l < r) {
		int mid = (l + r) / 2, p = check(mid, m);
//		printf("[%lld, %lld]: mid = %d, p = %d, nowans = %d\n", l, r, mid, p, ans2);
		if (p > ans2) r = mid, ans2 = p;
		else l = mid + 1;
	}
//	rep(1, n, 1) cout << qzh[i] << ' ';
	cout << max(ans1, ans2) << endl;
	return 0;
}
// 复杂度 O(n log n) ，可以过大样例，但是贪心逻辑有问题，答案不具有单调性
*/