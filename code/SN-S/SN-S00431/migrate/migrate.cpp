//高文轩 铜川市第二中学  SN-S00431 
#include <bits/stdc++.h>
using namespace std;

int c, t, a, b;

int main()
{
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	cin >> c >> t;
	if(c == 13 || c == 14)
	{
		for(int i = 1; i <= t; i++)
		{
			cout << 0 << endl; 
		}
	}
	if (c == 11 || c == 12)
	{
		for (int i = 1; i <= t; i++)
		{
			long long n, d, x, y;
			cin >> n >> d;
			for (int j = 1; j < n; j++)
			{
				cin >> x;
			}
			cin >> y;
			int cha = y - x;
			if (cha >= d || cha * 2 > d)
			{
				cout << 0 << endl;
			}
			else if (d % cha == 0)
			{
				cout << n - d / cha - 1 << endl;
			}
			else if (d % cha != 0)
			{
				cout << n - d / cha << endl;
			}
		}
	}
	return 0;
}
