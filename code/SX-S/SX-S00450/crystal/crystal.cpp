#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
const int N = 5e5 + 10;
int n, m;
int a[N];

bool check(int mid) {
	int tmp = m;
	for (int i = 1; i <= mid; i++) {
		int cha = a[mid] - a[i];
		if (tmp >= cha) {
			tmp -= cha;
		} else {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal4.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);

	int l = 1, r = n;
	int64 ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}