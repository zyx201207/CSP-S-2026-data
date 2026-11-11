/*
这可能是最后一战了。
你看到这段文字的时候，这个人可能已经 AFO 了。 
我该在哪里停留？我问我自己。 
愿世上永远没有 whk。
愿世上永远没有 JCer。
求求了给个 7 勾吧。 
							——lichenxi108 
*/


#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, ans;
long long m, a[N], sum[N];

inline bool check(int l, int r) {
//	cout << sum[r] - sum[l - 1] + m << ' ' << a[r] * (r - l + 1) << '\n';
	return sum[r] - sum[l - 1] + m >= a[r] * (r - l + 1);
}

int solve(int i) {
//	cout << i << ": \n";
	int l = 1, r = i;
	while (l < r) {
		int mid = (l + r) / 2;
//		cout << l << ' ' << r << ' ' << mid << '\n';
		if (check(mid, i)) r = mid;
		else l = mid + 1;
	}
//	cout << i - l + 1 << '\n';
	return i - l + 1;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, solve(i));
	}
	cout << ans;
	return 0;
} 
