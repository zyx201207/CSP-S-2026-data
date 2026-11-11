#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;

int c, t;
long long x[N];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		int n, d;
		cin >> n >> d;
		memset(x, 0, sizeof(x));
		for(int i = 1; i <= n; i++)
			cin >> x[i];
		long long k = x[2] - x[1];
		for(int i = 3; i <= n; i++)
		{
			if(x[i] - x[i - 1] != k)
			{
				cout << (n - 1) / 2 + (n - 1) % 2 << endl;
				break;				
			}
			if(i == n)
			{
				cout << n / d / 2 + (n / d) % 2 << endl;
			}
		}
	}
	
	return 0;
}
