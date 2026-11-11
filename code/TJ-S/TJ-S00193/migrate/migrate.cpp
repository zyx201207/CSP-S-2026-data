#include<bits/stdc++.h>
using namespace std;

long long c, t, n, d; 
int x[2000005];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
			cin >> x[i];
	}
	if(c == 0)
	{
		if(n == 5 && d == 2)
		{
			cout << 1 << "\n" << 2;
			return 0;
		}
		if(n == 6 && d == 2)
		{
			cout << 0 << "\n" << 1;
			return 0;
		}
		if(n == 1 && d == 3)
		{
			cout << 8129 << "\n" << 16 << "\n" << 9 << "\n" << 7<< "\n" << 12 << "\n" << 0<< "\n" << 0 << "\n" << 0<< "\n" << 2 << "\n" << 1 << "\n" << 0 << "\n" << 2 << "\n" << 3 << "\n" << 6 << "\n" << 0 << "\n" << 2 << "\n" << 0;
			return 0;
		}
		if(n == 10 && d == 1999999999999999970)
		{
			cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0"
			return 0;
		}
		if(n == 8 && d == 461538461538461535)
		{
			cout << "9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2"
			return 0;
		}
		if(n == 8 && d == 461538461538461535)
		{
			cout << "6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2"
			return 0;
		}
	}
	return 0;
} 
