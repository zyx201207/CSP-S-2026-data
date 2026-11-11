#include <bits/stdc++.h>
using namespace std;

long long c, t, n, d;
long long a[2000010];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		long long cha = abs(a[2]-a[1]);
		if (d < 2*cha || d >= a[n]-a[1])
		{
			cout << 0 << "\n";
			continue;
		}
		long long x = d/cha;
		cout << n-(2*x-1) << "\n";
	}
	
	return 0;
}
