#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n, ans, cnt;
long long m, a[N], xx;
bool p = 1;

long long check(int x) {
	long long minn = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= n - x + 1; i++) {
		long long goal = a[i + x - 1], sum = 0;
		for (int j = 0; j < x - 1; j++) {
			sum += goal - a[i + j];
		}
		minn = min(minn, sum);
	}
	return minn;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	freopen("1.in", "r", stdin);
//	freopen("my.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	xx = a[2] - a[1];
	for (int i = 3; i <= n; i++) {
		if (a[i] - a[i - 1] != xx) {
			p = 0;
			break;
		}
	}
	if (p) {
		for (int i = n - 1; i > 0; i--) {
			if (m >= a[n] - a[i]) {
				m -= a[n] - a[i];
				cnt++;
			} else {
				cout << cnt + 1;
				return 0;
			}
		}
		cout << cnt + 1;
		return 0;
	}
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		long long x = check(mid);
		if (x > m)
			r = mid - 1;
		else {
			l = mid + 1;
			ans = mid;
		}
	}
	cout << ans;
	return 0;
}
