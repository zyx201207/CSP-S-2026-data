#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
const int N = 200010;
int a[N], cnt[32];
bool vis[N];
std::vector<int>cho;

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m,  ans = (1LL << 32) - 1;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 30; j++)
			cnt[j] += ((a[i] >> j) & 1);
	}
	for (int j = 31; j >= 0; j--) {
		if (cnt[j] >= m) {
			for (int i = 1; i <= n; i++) {
				if (((a[i] >> j) & 1) && !vis[i]) {
					cho.push_back(a[i]);
					vis[i] = 1;
				}
			}
			if (cho.size() >= m)
				break;
		}
	}
	std::sort(cho.begin(), cho.end(), std::greater<int>());
	for (int i = 0; i < m; i++)
		ans &= cho[i];
	std::cout << ans;
	return 0;
}
