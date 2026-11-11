#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstdio>
#include <stdlib.h>
using namespace std;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int qwq, t;
	cin >> qwq >> t;
	while (t--)
	{
		int n, d;
		cin >> n >> d;
//		cout << (d - 3);
		vector <long long> a(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int cnt = 0;
		for (int i = 3; i < n; i++)
		{
			for (int j = 0; j < i - 2; j++)
			{
				bool f = true;
				for (int x = j; x < i; x++)
				{
					if (abs(a[x + 1] - a[x]) > d)
					{
						f = false;
						break;
					}
					if (abs(a[x + 2] - a[x]) > d && x < i - 1)
					{
						f = false;
						break;
					}
					if (abs(a[x + 3] - a[x]) <= d && x < i - 2)
					{
						f = false;
						break;
					}
				}
				if (f)
				{
					cnt++;
					cout << "   " << a[i] << " " << a[j] << endl;
					i++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
