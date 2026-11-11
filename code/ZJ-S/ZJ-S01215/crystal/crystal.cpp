#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	int n;
	int m;
	cin >> n;
	cin >> m; 
	int a[n + 5];
	int p = 1 , wz , M = m , o = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] != i && p == 1)
		{
			p = 0;
		}
		M -= i;
		if(M < 0 && o == 0)
		{
			wz = i;
			o = 1;
		}
	}
	if(p == 1)
	{
		cout << wz;
		return 0;
	}
	if(n == 1)
	{
		cout << 1;
		return 0;
	}
	sort(a + 1 , a + n + 1);
	for(int i = 2;i <= n;i++)
	{
		if(a[i] == a[i - 1])
		{
			continue;
		}
		if(m < (a[i] - a[i - 1]) * (i - 1))
		{
			cout << i - 1;
			return 0;
		}
		else
		{
			m -= (a[i] - a[i - 1]) * (i - 1);
		}
	}
	cout << n;
	return 0;
}
