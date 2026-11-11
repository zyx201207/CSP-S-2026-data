#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 5e5 + 10;

int n, ans;
LL m;
LL a[N];
LL s[N];

inline bool check(int l, int r, LL target) {
	return (m - target * (r - l + 1) + s[r] - s[l - 1] >= 0 ? 1 : 0);
}

int countLimit(int R, LL target) {
	int l = 1, r = R;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid, R, target))
			r = mid;
		else
			l = mid + 1;
	}
	return R - r + 1;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		int t = countLimit(i, a[i]);
		while (a[i + 1] == a[i])
			i++, t++;
		ans = max(ans, t);
	}
	cout << ans << '\n';
	return 0;
}