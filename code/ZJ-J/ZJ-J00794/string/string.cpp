#include <iostream>
#include <cstdio>
#include <cstdint>
#include <vector>

constexpr auto INPUT = "string.in";
constexpr auto OUTPUT = "string.out";

#define int int64_t

struct info { int a; char c; };

int32_t main()
{
#ifndef LOCAL_DEBUGING
	std::freopen(INPUT, "r", stdin);
	std::freopen(OUTPUT, "w", stdout);
#endif

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	std::vector<info> str;
	for (int i = 1; i <= n; i += 1)
	{
		info f;
		std::cin >> f.a >> f.c;
		str.push_back(f);
	}
	int l = 0, r = n - 1;
	int lcount = 0, rcount = 0;
	std::vector<info> left, right;
	while (l < r)
	{
		const int afterl = lcount + str[l].a;
		const int afterr = rcount + str[r].a;
		if (afterl > afterr)
		{
			right.push_back({ afterr - rcount, str[r].c });
			left.push_back({ afterr - lcount, str[l].c });
			str[l] = { afterl - afterr, str[l].c };
			r -= 1;
		}
		else if (afterl == afterr)
		{
			left.push_back(str[l]);
			right.push_back(str[r]);
			l += 1;
			r -= 1;
		}
		else
		{
			left.push_back({ afterl - lcount, str[l].c });
			right.push_back({ afterl - rcount, str[r].c });
			str[r] = { afterr - afterl, str[r].c };
			l += 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < left.size(); i += 1)
	{
		if (left[i].c != right[i].c)
		{
			ans += left[i].a;
		}
	}
	std::cout << ans;

	std::cout << std::flush;

	std::fclose(stdout);
	std::fclose(stdin);

	return 0;
}

