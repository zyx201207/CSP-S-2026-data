#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

constexpr auto INPUT = "card.in";
constexpr auto OUTPUT = "card.out";

int main()
{
#ifndef LOCAL_DEBUGING
	std::freopen(INPUT, "r", stdin);
	std::freopen(OUTPUT, "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;
	std::vector<int> cards(n + 1);
	std::vector<int> ans(m + 1, 0);
	for (int i = 1; i <= n; i += 1)
	{
		std::cin >> cards[i];
	}
	for (int i = 1; i <= n; i += 1)
	{
		std::map<int, int> mapping;
		std::vector<int> desk;
		for (int j = i; j <= n; j += 1)
		{
			int card = cards[j];
			const auto it = mapping.find(card);
			if (it == mapping.end())
			{
				desk.push_back(card);
				mapping[card] = desk.size() - 1;
			}
			else
			{
				int id = it->second;
				mapping.erase(it);
				for (int k = id; k < desk.size(); k += 1)
				{
					mapping.erase(mapping.find(desk[k]));
				}
				desk.erase(desk.begin() + id, desk.end());
			}
		}
		for (const int val : desk)
		{
			ans[val] += 1;
		}
	}
	for (int i = 1; i <= m; i += 1)
	{
		std::cout << ans[i] << ' ';
	}

	std::cout << std::flush;

	std::fclose(stdout);
	std::fclose(stdin);

	return 0;
}

