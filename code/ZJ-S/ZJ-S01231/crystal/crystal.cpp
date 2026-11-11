#include <iostream>
#include <algorithm>

long long arr[500001] = {};
long long ps[500001] = {};

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n = 0;
	long long m = 0;
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		std::cin >> arr[i];
	}
	std::sort(arr + 1, arr + n + 1);
	arr[n + 1] = arr[n] + 1;
	for (int i = 1; i <= n; ++i) {
		ps[i] = ps[i - 1] + arr[i];
	}
	
	int ans = 0;
	for (int i = 2; i <= n + 1; ++i) {
		if (arr[i] != arr[i - 1]) {
			int l = 1;
			int r = i - 1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				long long sum = ps[i - 1] - ps[mid - 1];
				long long cost = arr[i - 1] * (i - mid) - sum;
				
				if (cost <= m) {
					r = mid - 1;
				} else {
					l = mid + 1;
				}
			}
			
			ans = std::max(ans, i - l);
		}
	}
	
	std::cout << ans;
	
	return 0;
}