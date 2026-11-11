#include <bits/stdc++.h>
using namespace std;
int c[500086];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, a[500086], b[300086], q=1;
	cin >> n >> m;
	for(int p = m; p <= n; p++)
	{
		b[p]=-1;
	}
	for(int p = 1; p <= m; p++)
	{
		for(int i = p; i <= n; i++)
		{
			c[i]=0;
		}
		for(int i = p; i <= n; i++)
		{
			cin >> a[i];
			for(int j = 1; j <= i;j++)
			{
				if(a[i] != a[j] && c[j] == i-1)
				{
					c[j] = i; 
				}
			}
		}for(int i = p; i <= n; i++)
		{
			if(c[i] == n)
			{
				b[a[i]]++;
			} 
		}
	}while(b[q] > 0)
	{
		cout << b[q] << ' ';
	}
	return 0;
}
