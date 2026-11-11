#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5+10;
int n, m, a[maxn];

bool check2(int x, int s) {
	priority_queue<int, vector<int>, greater<int> > q;
	int f = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] <= s)
			q.push(s - a[i]), f++;
	if (f < x)
		return 0;
	int sum = 0;
	for (int i = 1; i <= x; i++) {
		sum += q.top();
		q.pop();
	}
	return sum <= m;
}

bool check(int x) {
	for (int i = 1; i <= n; i++)
		if (check2(x, a[i]))
			return 1;
	return 0;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int l = 1, r = n, ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid))
			ans = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	cout << ans;
	return 0;
}