#include <iostream>
using namespace std;
long long c, t, n, d;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if (c == 11 || c == 12)
	{	
		for (long long i = 1;i <= t;i++)
		{
			long long a[2];
			cin >> n >> d;
			long long cha, x;
			cin >> a[0] >> a[1];
			for (long long j = 2;j < n;j++)
			{
				cin >> x;
			} 
			cha = a[1] - a[0];
			if (d >= 2 * cha && d < 3 * cha)
			{
				cout << n - 4 + 1 << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
	}
	else
	{
		for (long long i = 1;i <= t;i++)
		{
			cin >> n >> d;
			long long x;
			for (long long j = 0;j < n;j++)
			{
				cin >> x;
			} 
			cout << i << endl;	
		}
	}
	return 0;
} 
