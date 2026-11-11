#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005], b[200004][32], d[32], zz;
bool c[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		int z = 1;
		while(a[i] > 0)
		{
			b[i][z] = a[i] % 2;
			z++;
			a[i] /= 2;
		}
	}
	for(int i = 31; i >= 1; i--)
	{
		int k = 0;
		for(int j = 1; j <= n; j++)
		{
			if(c[j])
			{
				continue;
			}
			if(b[j][i])
			{
				k++;
			}
		}
		if(k >= m)
		{
			d[i] = 1;
			for(int j = 1; j <= n; j++)
	    	{
		    	if(!b[j][i])
			    {
				    c[j] = true;
			    }
		    }
		}
	}
	long long w = 1;
	for(int i = 1; i <= 31; i++)
	{
	    if(d[i])
	    {
	    	zz += w;
		}
		w *= 2;
	}
	cout << zz;
	return 0;
}