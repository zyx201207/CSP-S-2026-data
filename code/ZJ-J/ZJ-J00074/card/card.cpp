#include <bits/stdc++.h>
using namespace std;
namespace Main
{
	int n, m;
	int a[500005];
	int mp[300005];
	int mmp[300005];
	void play(const int &x)
	{
		vector<int> v;
		memset(mmp + 1, 0, sizeof(int) * m);
		for (int i = x; i <= n; ++i)
		{
			if (mmp[a[i]])
			{
				int pos = mmp[a[i]];
				while (v.size() >= pos)
				{
					mmp[v.back()] = 0;
					v.pop_back();
				}
			}
			v.push_back(a[i]);
			mmp[a[i]] = v.size();
		}
		for (const int &x : v)
		{
			// cout << x << ' ';
			++mp[x];
		}
		// cout << '\n';
	}
	int main()
	{
		freopen("card.in", "r", stdin);
		freopen("card.out", "w", stdout);
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		for (int i = 1; i <= n; ++i)
			play(i);
		for (int i = 1; i <= m; ++i)
			cout << mp[i] << ' ';
		cout << '\n';
		return 0;
	}
}
int main()
{
	return Main::main();
}