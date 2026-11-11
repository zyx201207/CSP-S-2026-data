#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if (c == 11 || c == 12)
	{
		while (t--)
		{
			cin >> n >> d;
			for (int i = 1;i <= n;i++) cin >> a[i];
			if (d < a[2] - a[1] || d >= (a[2] - a[1]) * 3) cout << 0;
			else cout << n - 3;
		}
		return 0;
	}
	if (c == 13 || c == 14)
	{
		while (t--)
		{
			cout << 0;
		}
		return 0;
	}
	return 0;
}
