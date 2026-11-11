#define USE_FREOPEN
//#define IN_TEST

#include <iostream>
#include <algorithm>
int n, ans;
constexpr int MAXN = 5e5 + 5;
long long a[MAXN], m, sum[MAXN];
int main() {
#ifdef USE_FREOPEN
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n >> m;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
		
		int l = 0, r = i - 1, mid;
		long long disMin, getDis;
		while (l < r) {
			mid = (l + r) / 2;
			disMin = a[i] * (i - mid);
			getDis = sum[i] - sum[mid];
#ifdef IN_TEST
			std::cout << "i=" << i << ",mid=" << mid << ",disMin=" << disMin << ",getDis=" << getDis << std::endl;
#endif
			if (getDis + m >= disMin)
				r = mid;
			else
				l = mid + 1;
		}
		ans = std::max(ans, i - r);
	}
	std::cout << ans << std::endl;
}