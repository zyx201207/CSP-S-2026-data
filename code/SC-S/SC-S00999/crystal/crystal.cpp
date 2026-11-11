#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
ll a [N] , sum [N];

int main ()
{
	freopen ("crystal.in" , "r" , stdin);
	freopen ("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie (0);
	cout.tie (0);
	int n;
	ll m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a [i];
	} 
	if (m == 0)
	{
		cout << 0;
		return 0;
	} 
	bool flag = true;
	for (int i = 1;i <= n;i++)
	{
		if (a [i] != i)
		{
			flag = false;
		} 
	}
	if (flag == true)
	{
		ll cnt = 0;
		sum [n] = 0;
		for(int i = n - 1;i >= 1;i--)
		{
			sum [i] = sum [i + 1] + 1ll * n - i;
		}
		for (int i = n;i >= 1;i --)
		{
			if (m >= sum [i])
			{
				cnt ++;
			}
		}
		cout << cnt;
		return 0;
	}
	ll d = a [1] - a [2];
	bool flag2 = true;
	for (int i = 3;i <= n;i++)
	{
		if (a [i - 1] - a [i] != d)
		{
			flag2 = false;	
		}
	}
	if (flag2 == true)
	{
		ll cnt = 0;
		sum [n] = 0;
		for(int i = n - 1;i >= 1;i--)
		{
			sum [i] = sum [i + 1] + 1ll * abs (d)* (n - i);
		}
		for (int i = n;i >= 1;i --)
		{
			if (m >= sum [i])
			{
				cnt ++;
			}
		}
		cout << cnt;
		return 0;
	}
	ll cnt = 0;
	sort (a + 1 , a + n + 1);
	int mid = (n + 1) / 2;
	for (int i = 1;i <= n;i++)
	{
		if (a [i] == a[mid] && i != mid)
		{
			cnt ++;
		}
	}
	for (int i = mid;i >= 1;i --)
	{
		int cha = a [mid] - a [i];
		if (cha <= m)
		{
			cnt ++;
			m -= cha;			
		}
	}
	cout << cnt;
	return 0;
} 