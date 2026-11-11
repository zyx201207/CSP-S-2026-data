#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m;
int a[N];
bool check(int x);
long long calc(int h);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	long long l = LONG_LONG_MAX, r = LONG_LONG_MIN;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		l = min(l, a[i] * 1ll);
		r = max(r, a[i] * 1ll);
	}
	sort(a + 1, a + n + 1);
	long long h = 0;
	while (l < r) {
		int mid = (l + r) >> 1;
//		cout << l << ' ' << r << ' ' << mid << ' ' << boolalpha << check(mid) << endl;
		if (check(mid)) {
			l = mid + 1;
			h = mid;
		} else {
			r = mid;
		}
	}
	cout << calc(h);
	return 0;
}
bool check(int x) {
	long long cnt = 0;
	for (int i = n; i; i --) {
		if (a[i] < x && cnt + x - a[i] > m) {
			return false;
		}
		if (a[i] < x) {
			cnt += x - a[i];
		}
	}
	return true;
}
long long calc(int h) {
	int cnt = 0, cry = 0;
	for (int i = n; i; i --) {
		if (a[i] < h && cnt + h - a[i] > m) {
			break;
		}
		if (a[i] < h) {
			cry ++;
			cnt += h - a[i];
		}
	}
	for (int i = 1; i <= n; i ++) {
		if (a[i] == h) {
			cry ++;
		}
	}
//	cout << cnt << ' ';
	return cry;
}
