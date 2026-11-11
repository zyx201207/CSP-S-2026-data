#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int a[1005];

int main()
{
	int n, m;
	int ans = 0, sum = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int j = 0; j < m; j++)
	{
		if(a[j] = a[j+1] - a[j-1] - a[j-1])
		{
			ans = ans + 1;
		}
	}

	cout << ans;
	
	if(ans != 0)
	{
		return 0;
	}

	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int j = 0; j < m; j++)
	{
		if(a[j-2] = a[j-2] - a[j-2] + a[j+2])
		{
			sum = sum + 1;
		}
	}
	cout << sum;
	
	return 0;
}