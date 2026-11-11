#include <bits/stdc++.h>
using namespace std;

int main() {
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w" , stdout);
	
	long long n, m; cin >> n >> m;
	vector<long long> arr(n, 0);
	for (auto& x : arr) cin >> x;

	sort(arr.begin(), arr.end());

	vector<long long> miku(n);
	for (int i = 0; i < n - 1; i++) {
		miku[i] = arr[i + 1] - arr[i];
	}

	long long cost = 0, ans = -114514;
	for (long long l = 0, r = 0; r < n; r++, cost += (r - l) * miku[r - 1]) {
		while (cost > m) {
			cost -= arr[r] - arr[l];
			l++;
		}
		ans = max(ans, r - l + 1);
	}

	cout << ans;
}
