#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],z[300005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		vector <int> v;
		map <int,int> mp;
		for (int j = i;j <= n;j++)
		{
			int k = a[j];
			if (mp[k] == 0)
			{
				mp[k] = 1;
				v.push_back(k);
			}
			else
			{
				mp[k] = 1;
				int x = 0;
				for (auto i : v)
				{
					x++;
					if (i == k)
					{
						break;
					}
				}
				x = n - i - x;
				while (x--)
				{
					v.pop_back();
				}
				v.push_back(k);
			}
		}
		for (auto i : v)
		{
			z[i]++;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout << z[i] << " ";
	}
	return 0;
}
