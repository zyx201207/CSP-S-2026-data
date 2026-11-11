#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
int n, m;
long long a[N];
int item;
long long d[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i == 1) d[1] = 1;
		else d[i] = d[i-1] + i;
		
		if (i == 2)
		{
			item = a[i] - a[i-1];
		}
		else if (i > 2)
		{
			if (a[i] - a[i-1] != item)
			{
				item = 0x3f3f3f3f;
			}
		}
	}
	d[n+1] = 0x3f3f3f3f3f3f3f3f;
	
	if (item != 0x3f3f3f3f)
	{
		if (item == 0)
		{
			cout << n;
			return 0;
		}
		if (item == 1)
		{
			if (m >= d[n-1] )
			{
				cout << n;
				return 0;
			}
			for (int i = n - 1; i >= 1; i--)
			{
				if (m >= d[i] && m < d[i+1])
				{
					cout << i + 1;
					return 0;
				}
			}
		}
		else
		{
			if (m >= d[n-1]*item )
			{
				cout << n;
				return 0;
			}
			for (int i = n - 1; i >= 1; i--)
			{
				if (m >= d[i]*item && m < d[i+1]*item)
				{
					cout << i + 1;
					return 0;
				}
			}
		}
	}
	
	sort(a+1, a + n + 1);
	
	if (m == 0)
	{
		int maxp = 0, maxn = 1, now = a[1];
		for (int i = 2; i <= n; i++)
		{
			if (a[i] == now)
			{
				maxn++;
			}
			else
			{
				maxp = max(maxp, maxn);
				maxn = 1;
				now = a[i];
			}
		}
		cout << maxp;
		return 0;
	}
	
	cout << n;
	return 0;
}
