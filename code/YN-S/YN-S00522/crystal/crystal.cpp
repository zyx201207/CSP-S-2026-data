#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> vec;
vector<int> sum;
int n, m;

bool check(int thres) {
	for (int i = thres; i <= n; i++) {
		int diff = vec[i] * (thres - 1) -
		           (sum[i - 1] - sum[i - thres]);
		if (diff <= m)
			return true;
	}
	return false;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vec.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> vec[i];
	}
	sort(vec.begin() + 1, vec.end());
	sum.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + vec[i];
	}
	int l = 1, r = n;
	while (l < r) {
//		cout << l << endl;
		int mid = (l + r + 1) >> 1;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << l << endl;
	return 0;
}