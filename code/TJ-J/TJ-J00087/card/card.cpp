#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	int n, m;
	cin >> n >> m;
	vector <int> a(n, 0);
	vector <int> less(m, 0);
	vector <int> cnt(m, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int j = 0; j < n; j++)
	{
		//game
		for (int i = j; i < n; i++)
		{
			bool flag = false;
			int note = 0;
			for (int k = 0; k < m; k++)
			{
				if (less[k] == a[i])
				{
					flag = true;
					note = k;
					break;
				}
			}
			if (flag)
			{
				for (int k = 0; k < m - note; k++)
				{
					less[k] = less[k + note];
					less[k + note] = 0;
				}
			}
			else
			{
				for (int k = m - 1; k >= 1; k--)
				{
					less[k] = less[k - 1];
				}
				less[0] = a[i];
			}
		}
//		for (int i = 0; i < m; i++) cout << less[i] << " ";
		for (int i = 0; i < m; i++)
		{
			if (!less[i]) continue;
			cnt[less[i]-1]++;
		}
		for (int i = 0; i < m; i++) less[i] = 0;
//		cout << endl;
	}
	for (int i = 0; i < m; i++) cout << cnt[i] << " ";
	return 0;
}
