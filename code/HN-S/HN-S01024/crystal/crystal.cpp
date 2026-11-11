#include <bits/stdc++.h>

using ll = long long;
#define f first
#define s second
const int inf = (1 << 30) - 1;
const ll INF = 1ll << 60;

const int N = 5e5 + 10;
int n, ans;
ll m, a[N], sum[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) std::cin >> a[i];
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		int l = 0, r = i + 1;
		while (l + 1 < r) {
			int mid = l + r >> 1;
			if ((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m) r = mid;
			else l = mid;
		}
		ans = std::max(ans, i - r + 1);
	}
	std::cout << ans << '\n';
} 
