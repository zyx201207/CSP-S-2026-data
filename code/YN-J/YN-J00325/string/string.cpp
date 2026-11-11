#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	int n;
	cin >> n;

	vector<pair<char, int>> s;

	char lt = 'Q';

	bool issame = true;
	for (int i = 0 ; i < n ; ++i)
	{
		char t1;
		int t2;

		cin >> t2 >> t1;

		s.push_back( {t1, t2} );

		if (t1 != lt && i != 0)
		{
			issame = false;
		}

		lt = t1;
	}

	if (issame)
	{
		cout << 0 << '\n';
		return 0;
	}

	long long ans = 0;
	for (size_t i = s.size() - 1 ; i >= s.size() / 2 ; --i)
	{
		if (s[i].first == s[s.size() - i - 1].first)
		{
			if (s[i].second != s[s.size() - i - 1].second)
			{
				ans += abs(s[i].second - s[s.size() - i - 1].second);
			}
		}
		else
		{
			ans += min(s[i].second, s[s.size() - i - 1].second);
		}
	}
	cout << ans << '\n';

	return 0;
}
