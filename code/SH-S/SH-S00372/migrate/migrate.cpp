#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000100],cnt;
int dis[2000100],count[2000100];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for(int i = 1;i <= t;i++)
	{
		cin >> n >> d;
		for(int i = 1;i <= 2;i++)
		{
			cin >> x[i];
		}
		if(2 * (x[2] - x[1]) > d)
		{
			cout << 0 << endl;
			continue;
		}
		else
		{
			cout << n - 2 * (d/(x[2] - x[1])) + 1 << endl;
			continue;
		}
	}
}
