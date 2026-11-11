#include <bits/stdc++.h>
using namespace std;
long long n,x[2000005],d,c,t,num,ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin >> c >> t;
	if (c == 11 || c == 12)
	{
		for (int T = 1;T <= t;T++)
		{
			cin >> n >> d;
			for (int i = 1;i <= n;i++)
			{
				cin >> x[i];
			}
			c = abs(x[2] - x[1]);
			num = d / c;
			if (num >= 2)
			{
				ans = n - (num * 2 - 1);
				if (ans <= 0)
				{
					cout << 0 << endl;
				}
				else 
				{
					cout << ans << endl;
				}
			}
			else 
			{
				cout << 0 << endl;
			}
		}
	}
	return 0;
}

