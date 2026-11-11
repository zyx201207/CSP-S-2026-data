#include <bits/stdc++.h>
using namespace std;
int n, m, x[300005], cnt[300005];
int main()
{
	//bian bo yang 西安市第一中学 SN-J00740
	//freopen("card.in", "r", stdin);
	//freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector <int> a;
	vector <int> b;
	cin >> n >> m;
	a.push_back(4e9);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		memset(x, -1, sizeof(x));
		a.erase(a.begin());
		int w = -1;
		for (int j = 0; j < n; j++)
		{
			if (x[a[j]] == -1)
			{
				b.push_back(a[j]);
				w++;
				x[a[j]] = w;
			}
			else
			{
				for (int k = x[a[j]]; k < b.size(); k++)
				{
					w--;
					x[k] = -1;
			    }
				b.erase(b.begin() + x[a[j]], b.end());
			}
		}
		for (int j = 0; j < b.size(); j++)
		{
			cnt[b[j]]++;
		}
		for (int j = 0; j < b.size(); j++)
		{
			b.erase(b.begin());
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << cnt[i] << " ";
	}
	return 0;
}
