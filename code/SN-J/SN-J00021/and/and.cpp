#include<bits/stdc++.h> 
using namespace std;
int n, m, a[2010];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if(m == n)
	{
		for(int i = 1; i < n; i++)
		{
			a[i] = (a[i] & a[i - 1]);
		}
		cout << a[n - 1];
		return 0;
	}
	if(m == 2)
	{
		int maxn = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = i + 1; j < n; j++)
			{
				if((a[i] & a[j]) > maxn)
				{
					maxn = (a[i] & a[j]);
				}
			}
		}
		cout << maxn;
		return 0;
	}
	int maxn = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] > maxn)
		{
			maxn = a[i];
		}
	}
	cout << maxn;
	return 0;
}
