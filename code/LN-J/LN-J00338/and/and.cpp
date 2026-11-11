#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[200001];
int maxn = 0;

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if(m == 1)
	{
		for(int i = 0; i < n; i++)
		{
			if(a[i] > maxn)
				maxn = a[i];
		}
	}
	if(m == n)
	{
		int s = a[0];
		for(int i = 1; i < n; i++)
		{
			s = s & a[i];
		}
		maxn = s;
	}
	if(m == 2)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = i; j < n; j++)
			{
				if(a[i] & a[j] > maxn)
					maxn = a[i] & a[j];
			}
		}
	}
	cout << maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
