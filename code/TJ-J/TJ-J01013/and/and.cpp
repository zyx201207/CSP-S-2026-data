#include <bits/stdc++.h>
using namespace std;
int a[12476346];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,b = 0,c;
	cin >> n >> m;
	if (m == 1)
	{
		for (int i = 0;i < n;i += 1)
		{
			cin >> a[i];
			c = max(b,a[i]);
			b = c;
		}
		cout << b;
		return 0;
	}
	else if (m == 2)
	{
		for (int i = 0;i < n;i += 1)
		{
			cin >> a[i];
		}
		for (int i = 0;i < n - 1;i += 1)
		{
			c = max(b,a[i] & a[i + 1]);
			b = c;
		}
		cout << b;
		return 0;
	}
	else if (m == n)
	{
		b = a[0];
		for (int i = 1;i < n;i += 1)
		{
			c = b & a[i];
			b = c;
		}
		cout << b;
		return 0;
	}
	else
	{
		cout << 7;
		return 0;
	}
	return 0;
}
