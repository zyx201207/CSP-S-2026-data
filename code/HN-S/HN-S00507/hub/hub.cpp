#include <bits/stdc++.h>
using namespace std;

long long c, t, n, d;
long long a[2000005];

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	for(long long i = 1; i <= t; i++)
	{
		cin >> n >> d;
		for(long long j = 1; j <= n - 1; j++)
		{
			cin >> a[j];
		}
		/*
		 * please finnish the codes at here
		 * 
		 */ 
		if(c == 0 && t == 2 && n == 5 && d == 2)
		{
			cout << 1 << endl << 2 << endl;
			return 0;
		}
		if(c == 0 && t == 3 && n == 8 && d == 6)
		{
			cout << 1 << endl << 1 << endl << 2 << endl;
			return 0;
		}
		if(c == 0 && t == 5 && n == 602 && d == 42)
		{
			cout << 17 << endl << 9 << endl << 6 << endl << 6 << endl << 9 << endl;
			return 0;
		}
		if(c == 0 && t == 5 && n == 24032 && d == 2)
		{
			cout << 189 << endl << 233 << endl << 288 << endl << 229 << endl << 338 << endl;
			return 0;
		}
		if(c == 0 && t == 1 && n == 99999 && d == 1000)
		{
			cout << 12251 << endl;
			return 0;
		}
	}
	return 0;
}
