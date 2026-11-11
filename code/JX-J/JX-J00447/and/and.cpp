#include <bits/stdc++.h>

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int N, m;
	std:: cin >> N >> m;
	std:: vector<int> arr(N + 1);
	std:: vector<bool> vis(N + 1);
	
	for (int i = 1; i <= N; ++i)
	{
		int x;
		std:: cin >> x;
		arr[i] = x;
	}
	
	int ct = 0, res = 0;
	for (int k = 30; k >= 0; --k)
	{
		int nct = 0, zct = 0;
		std:: vector<std:: pair<int, int>> p;
		for (int i = 1; i <= N; ++i)
		{
			if ((arr[i] >> k) & 1)
			{
				++zct;
				if (!vis[i])
				{
					++nct;
					p.push_back(std:: make_pair(arr[i], i));
				}
			}
		}
		
		if (zct >= m)
		{
			int od = zct - nct;
			if (od < m)
			{
				int d = m - od;
				if (ct + d <= m)
				{
					ct += d;
					res |= (1 << k);
					std:: sort(p.begin(), p.end(),
						std:: greater<std:: pair<int, int>>());
					for (int i = 0; i < d; ++i)
					{
						vis[p[i].second] = 1;
					}
				}
			}
			else res |= (1 << k);
		}
	}
	
	std:: cout << res << "\n";
	return 0;
}
