#include <bits/stdc++.h>
using namespace std;
int c , t , n , d , sum;
int main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	cin >> c >> t;
	if (c == 11 || c == 12)
	{
		int a , b , cha;
		while (t--)
		{
			cin >> n >> d >> a >> b;
			cha = b - a;
			if (d < cha)
			{
				cout << 0 << endl;
				continue;
			}
			int num = d / cha;
			for (int len = 1 ; len < n ; len++)
			{
				if (len % num == 0)
				{
					continue;
				}
				sum += n - len;
			} 
			cout << sum << endl;
		}
	}
	else
	{
		while (t--)
		{
			cout << 0 << endl;
		}
	}
	return 0;
}
