#include <algorithm>
#include <iostream>
#include <cstdio> 
#include <map>
#define ll long long
using namespace std;

ll x[2000010];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ll c, T;
	cin >> c >> T;
	while (T--)
	{
		ll n, d;
		cin >> n >> d;
		for (ll i = 1; i <= n; i++)
		{
			cin >> x[i];
		}
		ll dt = x[2] - x[1];
		ll minn = dt;
		bool f = true;
		for (ll i = 3; i <= n; i++)
		{
			minn = min(minn, x[i] - x[i - 1]);
			if (dt != x[i] - x[i - 1])
			{
				f = false;
			}
		}
		if (f)
		{
			if (dt >= d)
			{
				cout << 0 << '\n';
			} 
			else
			{
				ll maxn = d / dt;
				if (maxn <= 1)
				{
					cout << 0 << '\n';
				}
				else
				{
					ll zero = 0;
					ll ans = max(n - 2 * maxn + 1, zero);
					cout << ans << '\n';
				}
			}
		}
		else
		{
			if (minn >= d)
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << 1 << '\n';
			}
			
		}
		
	}
	return 0;
}
//-static-libgcc
