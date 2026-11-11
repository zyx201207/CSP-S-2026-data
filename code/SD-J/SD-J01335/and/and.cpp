#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm> 

long long n, m, ans = 0;
long long nums[int(2e5) + 6]; 
bool used[int(2e5) + 6] = {false}; 

void dfs(long long t, long long a_sum, long long last) {
	if (t == m) {
		ans = std::max(ans, a_sum);
		return;
	}
	
	for (int i = last + 1; i < n; i++) {
		if (used[i]) continue;
		used[i] = true;
		dfs(t + 1, a_sum & nums[i], i);
		used[i] = false;
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	std::cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		std::cin >> nums[i];
	}
	
	for (long long i = 0; i < n - m; i++) {
		used[i] = true;
		dfs(1, nums[i], i);
		used[i] = false;
	}
	std::cout << ans;
	
	return 0;
}
