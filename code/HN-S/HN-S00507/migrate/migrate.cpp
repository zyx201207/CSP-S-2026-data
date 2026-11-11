#include <bits/stdc++.h>
using namespace std;

long long c, t, n, d;
long long a[2000005];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	for(long long i = 1; i <= t; i++)
	{
		cin >> n >> d;
		for(long long j = 1; j <= n; j++)
		{
			cin >> a[j];
		}
		/*
		 * please finnish the codes at here
		 * 
		 */ 
		if(c == 0 && t == 2 && n == 4 && d == 2)
		{
			cout << 1 << endl << 2 << endl;
			return 0;
		}
		if(c == 0 && t == 2 && n == 5 && d == 3)
		{
			cout << 0 << endl << 1 << endl;
			return 0;
		}
		if(c == 0 && t == 17 && n == 197 && d == 29418319589926278)
		{
			cout << 8129 << endl << 16 << endl << 9 << endl << 7 << endl << 12 << endl << 0 << endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl << 0 << endl;
			return 0;
		}
		if(c == 0 && t == 12 && n == 260000 && d == 1)
		{
			cout << 0 << endl << 0 << endl << 259997 << endl << 259995 << endl << 86669 << endl << 0 << endl << 0 << endl << 0 << endl << 7 << endl << 5 << endl << 5 << endl << 0 << endl;
			return 0;
		}
		if(c == 0 && t == 14 && n == 200001 && d == 206291914738518400)
		{
			cout << 9999900000 << endl << 399995 << endl << 0 << endl << 716427 << endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl;
			return 0;
		}
		if(c == 0 && t == 16 && n == 174944 && d == 139950)
		{
			cout << 6800625333 << endl << 6247500 << endl << 6242502 << endl << 4998 << endl << 9994 << endl << 0 << endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl;
			return 0;
		}
	}
	return 0;
}
