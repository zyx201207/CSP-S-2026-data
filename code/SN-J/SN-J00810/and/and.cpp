// Íõ¿¬ä¿ SN-J00810 
#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200004];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	long long k = -1;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	if (m == 1)
	{
		for(int i = 1;i <= n;i++)
			k = max(k,a[i]);
	}
	else if (m == n)
	{
		k = 1;
		for(int i = 1;i <= n;i++)
			k &= a[i];
	}
	else if (m == 2)
	{
		for(int i = 1;i < n;i++)
		{
			for(int j = i + 1;j <= n;j++)
				k = max(k,a[i] & a[j]);
		}
	}
	else
	{
		long long fl = 1;
		bool flag = false;
		for(int i = 1;i <= n;i++)
		{
			if (m <= 0)
				break;
			if (fl <= fl & a[i])
			{
				m--;
				fl &= a[i];
				flag = true;
			}
		}
		if (!flag)
			k = 0;
		else
			k = fl;
	}
	cout << k;
	return 0;
}
