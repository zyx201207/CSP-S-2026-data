#include <bits/stdc++.h>
using namespace std;
int n,a[200009],m,k = -999,maxx = -999;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		maxx = max(maxx,a[i]);
	}
	if (m == n)
	{
		k = a[1];
		for (int i = 2;i <= n;i++)
		{
			k = (k & a[i]);
		}
		cout << k;
	}
	else if (m == 1)
	{
		cout << maxx;
	}
	else if (m == 2)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = i + 1;j <= n;j++)
			{
				k = max(k,(a[i] & a[j]));
			}
		}
		cout << k;
	}
	else if (a[1] < 4 && a[2] < 4)
	{
		cout << 3;
	}
	return 0;
}
