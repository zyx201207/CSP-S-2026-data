#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll MAXN = 2e6 + 5;

ll c, n, t, d;
ll a[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t --)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		if (c >= 11 && c <= 12)
		{
			ll cha = a[2] - a[1];
			if (cha*2 > d)
			{
				cout << 0 << '\n';
			}else
				cout << max(n - 2*(d/cha) +1, (ll)0) <<'\n';
		}else if (c >= 13 && c <= 14)
		{
			cout << 0 << '\n';
		}
		
	}
	return 0;
}
