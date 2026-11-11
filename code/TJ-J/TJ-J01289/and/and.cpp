#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m, a[200086], c[200086], x, maxx = -1, b[32], ma;
	cin >> n >> m;
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
		c[i] = a[i];
		x = 0;
		while(0 < c[i])
		{
			x++;
			if(c[i]%2 == 1) b[x]++;
			c[i] /= 2;
		}
		if(x > maxx)
		{
			maxx = x;
		}
	}for(long long i = maxx; i >= 1; i--)
	{
		if(b[i] >= m)
		{
			ma += pow(2,i);
		}
	}cout << ma;
	return 0;
} 
