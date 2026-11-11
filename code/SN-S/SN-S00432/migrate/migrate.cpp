#include<bits/stdc++.h>
using namespace std;
long long c, T;
long long n, m;
long long a[2000005];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> T;
	while(T--)
	{
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		long long ans = n - (m / (a[2] - a[1])) - (m / (a[2] - a[1])) + 1;
		if(((a[2] - a[1]) * 2 > m) || (ans < 0))
		{
			cout << 0 << endl;
			continue;
		}
		cout << ans <<endl;
	}
	return 0;
}
