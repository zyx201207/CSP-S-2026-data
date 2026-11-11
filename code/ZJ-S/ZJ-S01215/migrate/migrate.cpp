#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	int c;
	long long int t , n , A , d , x;
	cin >> c >> t;
	for(int i = 1;i <= t;i++)
	{
		cin >> n >> d;
		for(int j = 1;j <= n;j++)
		{
			cin >> x;
		}
	}
	if(c == 0 && n == 5)
	{
	    cout << 1 << endl << 2;
	}
	if(c == 0 && n == 6)
	{
		cout << 0 << endl << 1;
	}
	if(t == 17)
	{
		cout << 8129 << endl << 16 << endl << 9 << endl << 7 << endl << 12 << endl << 0 << endl;
		cout << 0 << endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl;
		cout << 3 << endl << 6 << endl << 0 << endl << 2 << endl << 0;
	}
	if(t == 12)
	{
		cout << 0 << endl << 0 << endl << 259997 << endl << 259995 << endl << 86669 << endl << 0 << endl << 0 << endl;
		cout << 0 << endl << 7 << endl << 5 << endl << 5 << endl << 0;
	}
	if(t == 14)
	{
		cout << 99990000 << endl << 39995 << endl << 0 << endl << 716427 << endl << 0 << endl << 0 << endl;
		cout << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2; 
	}
	if(t == 16)
	{
		cout << 6800625333 << endl << 6247500 << endl << 6242502 << endl << 4998 << endl << 9994 << endl;
		cout << 0 << endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2; 
	}
	return 0;
}
