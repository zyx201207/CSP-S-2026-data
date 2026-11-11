#include<bits/stdc++.h>
#define int long long
#define ls(x) x<<1
#define rs(x) x<<1|1
#define endl '\n'

using namespace std;

const int N = 5e5 + 10;

int n, m, a[N], mx = -1e18, mn = 1e18, ans;

bool cmp(int x, int y) {
	return x > y;
}

int get(int k) {
	vector<int> tmp;
	for (int i = 1; i <= n; ++i) {
		if (a[i] <= k) {
			tmp.push_back(a[i]);
		}
	}
	sort(tmp.begin(), tmp.end(), cmp);
	int cost = 0, cnt = 0;
	for (int i = 0; i < tmp.size(); ++i) {
		if (cost + (k - tmp[i]) <= m) {
			cost += k - tmp[i];
			cnt++;
		}
	}
	return cnt;
}

bool check(int k) {
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] < k) {
			cnt += k - a[i];
		}
	}
	return cnt <= m;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	bool f = 0, f2 = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
		if (a[i] != i) f = 1;
		if (i > 2 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) f2 = 1;
	}
	if (!f) {
		for (int i = n; i >= 1; --i) {
			int d = a[n] - a[i];
			if ((m - d) >= 0) {
				m -= d;
				ans++;
			}
		}
		cout << max(ans, 1) << endl;
		return 0;
	}
	if (!f2) {
		for (int i = n; i >= 1; --i) {
			int d = a[n] - a[i];
			if ((m - d) >= 0) {
				m -= d;
				ans++;
			}
		}
		cout << max(ans, 1) << endl;
		return 0;
	}
	if (mx <= 100) {
		for (int i = mn; i <= mx; ++i) {
			ans = max(ans, get(i));
		}
		cout << max(ans, 1) << endl;
		return 0;
	}
	else {
		int l = mn, r = mx, res = 0;
		while (l < r) {
			int mid = l + r >> 1;
			if (check(mid)) l = mid + 1, res = mid;
			else r = mid - 1;
		}
		int sum = 0;
		for (int i = 1; i <= n; ++i){
			if (a[i] <= res) {
				sum++;
			}
		}
		cout << max(sum, 1) << endl;
		return 0;
	}
	return 0;
}
