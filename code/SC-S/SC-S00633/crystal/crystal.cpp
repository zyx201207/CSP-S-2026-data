#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m,sum = 0;
int nums[N];
bool check(int x) {
	//cout << x << ' ';
	unsigned sum2 = sum;
	for (int i = n - 1; i >= x; -- i) {
		sum2 -= nums[i];
	}
	sum2 += m;
	//cout << sum2 << ' ';
	sum2 /= x;
	//cout << sum2 << '\n';
	if(sum2 >= nums[x - 1]) return true;
	else return false;
}

void solve() {
	
	cin >> n >> m;
	for (int i = 0; i < n; ++ i) {
		cin >> nums[i];
		sum += nums[i];
	}
	int l = 1, r = n, ans = 0;
	sort(nums, nums + n);
	while(l <= r) {
		int m = l + (r - l) / 2;
		if(check(m)) {
			l = m + 1;
			ans = max(ans, m);
		} else {
			r = m - 1;
		}
	}
	cout << ans;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int T = 1;
	//cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}