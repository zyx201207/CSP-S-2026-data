#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	int n, m;
	cin >> n >> m;

	vector<int> table(n), cards(n), bm(m), ans(m);
	for (auto &i : cards)
	{
		cin >> i;
	}

	for (int i = 0 ; i < n ; ++i)
	{
		table.clear();
		for (auto &i : bm)
		{
			i = -1;
		}
		table.reserve(n);

		for (int j = i ; j < n ; ++j)
		{
			table.push_back(cards[j]);
			if (bm[table[table.size() - 1] - 1] != -1)
			{
				for (size_t k = bm[table[table.size() - 1] - 1] ; k < table.size() ; ++k)
				{
					if (k >= table.size() || bm[table[k] - 1] >= table.size())
					{
						break;
					}

					int now = table[k];
					table.erase(table.begin() + (bm[now - 1]));
					bm[now - 1] = -1;
				}
			}
			else
			{
				bm[table[table.size() - 1] - 1] = j;
			}

		}

		for (const auto &j : table)
		{
			++ans[j - 1];
		}
	}

	for (const auto &i : ans)
	{
		cout << i << ' ';
	}
	cout << '\n';

	return 0;
}
