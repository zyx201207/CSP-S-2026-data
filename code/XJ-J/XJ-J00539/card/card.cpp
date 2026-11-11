#include <bits/stdc++.h>
using namespace std;

long long n , m , o ;
long long a[100000] , b[100000] , c[100000];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			for(int q = i;q <= n;q++)
			{
				if(a[j] == b[q])
				{
					o = q;
					for(int p = o;p <= n;p++)b[p] = 0;
					b[o] = a[j];
				}
				else
				{
					int f = i;
					while(b[f] != 0)
					{
						f++;
					}
					b[f] = a[j];
				}
			}
		}
		for(int j = 1;j <= m;j++)
		{
			for(int q = 1;q <= n + 1;q++)
			{
				if(b[q] == j)c[j]++;
			}
		}
		for(int j = 1;j <= n;j++)b[j] = 0;
	}
	for(int i = 1;i <= m;i++)
	{
		cout << c[i] << " ";
	}
	return 0;
}