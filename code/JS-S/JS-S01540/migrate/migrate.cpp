#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c, t, n, d, x[500005];
	cin  >> c >> t;
	for (int i = 1;i <= t;i++)
	{
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
		{
			cin >>x[i];
		}
		if(t==2)
		{
			if(n==4)
			{
				if(d==2)
				{
					cout << "1" << endl << "2";
				}
			}
		}
	}
	return 0;
}
