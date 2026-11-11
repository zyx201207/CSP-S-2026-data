#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pir;

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<ll>a(n + 1, 0);

	vector<ll>dre(n + 1, 0);
	vector<ll>pre(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a.begin() + 1, a.end());

	for (int i = n - 1; i >= 1; i--) {
		dre[i] = dre[i + 1] + (a[n] - a[i]);
	}
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}

	/*
	考虑二分：
	枚举终点，二分其对应起点，
	试想快速计算区间代价的方法
	*/

	auto work = [&](int l, int r) {
		if (r == n) {
			return dre[l];
		}
		return (dre[l] - dre[r + 1]) - (r - l + 1) * a[n] + (r - l + 1) * a[r];
	};
	/*
		for (int i = 1; i <= n; i++) {
			cout << dre[i] << ' ';
		}
		cout << '\n';
	*/
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		if (i == 1)
			continue;
		int l = 1, r = i - 1;
		int tempid = i - 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (work(mid, i) <= m) {
				r = mid - 1;
				tempid = min(tempid, mid);
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - tempid + 1);
	}
	/*
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				cout << i << ' ' << j << ' ' << work(i, j) << '\n';
			}
		}
	*/
	cout << ans << '\n';
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	solve();
	return 0;
}