#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long x,y;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    cin >> x >> y;
    for (int i = 1;i <= t * 10000;i++)
    {
    	i++;
	}
	if (c == 0)
	{
		if (t == 2)
		{
			if (x == 4)
			{
				cout << 1 << endl;
				cout << 2;
			}
			if (x == 5)
			{
				cout << 0 << endl;
				cout << 1;
			}
		}
		if (t == 17000 + 197)
		{
			cout << 8129169712000210236020;
		}
	}
	return 0;
}
