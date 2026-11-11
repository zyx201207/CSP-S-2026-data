#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 5e5 + 5;
int nums[N];
int sum[N];

int binary_search(int high) {
	int l = 1, r = high;
	while (l < r) {
		int mid = (l + r) / 2;
		if (nums[high - 1] * (high - mid + 1) - sum[high] + sum[mid - 1] <= m) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return r - 1;
}

long long solve() {
	sort(nums, nums + n);
	for (int i = 0; i < n; ++i) {
		sum[i + 1] = sum[i] + nums[i]; 
	}
	
	long long result = 1;
	for (int i = 1; i <= n; ++i) {
//		cout << nums[i - 1] << ' ' << i << ' ' << sum[i] << endl;
		int idx = binary_search(i);
		result = max(result, (long long)(i - idx));
	}
	return result;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(false);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	
	cout << solve() << endl;
	
	return 0;
}
