#include <iostream>
#include <cstdio>
#include <cstdint>
#include <vector>
#include <limits>
#include <functional>

constexpr auto INPUT = "and.in";
constexpr auto OUTPUT = "and.out";

constexpr int32_t INF = std::numeric_limits<int32_t>::max();

int32_t main()
{
#ifndef LOCAL_DEBUGING
	std::freopen(INPUT, "r", stdin);
	std::freopen(OUTPUT, "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int32_t n, m;
	std::cin >> n >> m;
	std::vector<int32_t> vec(n + 1);
	for (int32_t i = 1; i <= n; i += 1)
	{
		std::cin >> vec[i];
	}
	int32_t ans = 0;
	const std::function<void(size_t, int32_t, int32_t)> dfs =
		[&](const size_t x, const int32_t ch, const int32_t va)	{
		if (x > n)
		{
			if (ch == m)
			{
				ans = std::max(ans, va);
			}
			return;
		}
		if (ch < m && (va & vec[x]) > ans)
		{
			dfs(x + 1, ch + 1, va & vec[x]);
		}
		dfs(x + 1, ch, va);
	};
	dfs(1, 0, INF);
	std::cout << ans;

	std::cout << std::flush;

	std::fclose(stdout);
	std::fclose(stdin);

	return 0;
}

