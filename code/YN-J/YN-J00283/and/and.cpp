#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
ll n, m;
ll a[N];

bool cmp(ll x, ll y)
{
	return x > y;
}
ll p = 0;

ll main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	if (m == n)
	{
		ll t = a[1];
		for (ll i = 1; i <= n; i++)
		{
			t &= a[i];
		}
		cout << t << '\n';
		return 0;
	}
	if (m == 1)
	{
		cout << a[1] << '\n';
		return 0;
	}
	if (m == 2)
	{
		ll maxn = -1e9;
		for (ll i = 1; i <= n; i++)
		{
			for (ll j = 1; j <= n; j++)
			{
				if (i == j)
				{
					continue;
				}
				maxn = max(maxn, a[i] & a[j]);
			}
		}
		cout << maxn << '\n';
		return 0;
	}
	if(m==n-1){
		ll t = a[1];
		for(ll i=1;i<=m;i++){
			t&=a[i];
		}
		cout<<t<<'\n';
		return 0;
	}
	cout << a[m] << '\n';
	return 0;
}
