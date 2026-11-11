#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	int cnt = 0;
	cin >> n>> m;
	int a[n], cn[n];
	for(int i = 1; i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(a[i] == j)
			cn[i] -= a[j];
		}
		return 0;
	}
	return 0;
}

