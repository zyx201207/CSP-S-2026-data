#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, a[500005], s[500005], ans = -1;
bool des = true;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(i != 1 && a[i] - a[i - 1] != a[2] - a[1])
			des = false;
	}
	if(n == 1)
	{
		cout << 1;
		return 0;
	}
	sort(a + 1, a + n + 1);
	if(des)
	{
		ll cost = 0, lst = 0;
		for(int i = 2; i <= n; i++)
		{
			cost = (i - 1) * (a[1] + a[i]) / 2;
			if(cost > m)
			{
				cout << i - 1;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		s[i] = s[i - 1] + a[i];
	}
	ll cost, minn = 1e12;
	for(ll i = 1; i <= n; i++)
	{
		for(ll j = i + 1; j <= n; j++)
		{
			cost = (j - i) * a[j] - (s[j - 1] - s[i - 1]);
			//cout << cost << ' ';
			if(cost - m >= 0 && cost - m <= minn)
			{
				minn = min(minn, cost - m);
				ans = max(ans, j - i + 1);
			}
		}
	}
	cout << ans;
	return 0;
}
