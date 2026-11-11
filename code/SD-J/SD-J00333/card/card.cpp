#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> a;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	vector<int> k(m + 5);
	fill(k.begin(), k.end(), 0);
	for (int i = 1; i <= n; i++)
	{
		int w;
		cin >> w;
		a.push_back(w);
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i - 1; j < n;j++)
		{
			k[a[j]]++;
			if (k[a[j]] == 2)
			{
				fill(k.begin() + a[j] + 1, k.end(), 0);
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		if (k[i] != 0)
		{
			cout << k[i] << " ";
		}
	}
	return 0;
}
