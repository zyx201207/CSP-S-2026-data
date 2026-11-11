#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int x[N]; 
bool check(int i , int j)
{
	
}
signed main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c , t;
	cin >> c >> t;
	while (t--)
	{
		int n , d;
		cin >> n >> d;
		int minn = LLONG_MAX;
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i];
			minn = min(minn , abs(x[i] - x[i - 1]));
		}
		if (minn > d)
		{
			cout << "0\n";
			continue;
		}
		if (n < 4)
		{
			cout << "0\n";
			continue;
		}
		if (minn == d)
		{
			cout << "0\n";
			continue;
		}
		int tot = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (check(i , j) == 1) tot++;
			}
		}
		cout << tot << "\n"; 
	}
	return 0;
}

