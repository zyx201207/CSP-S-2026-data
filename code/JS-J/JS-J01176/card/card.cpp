#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int a[n];
	int b[n];
	int c[m];
	for (int i = 0; i < n; ++i)cin >> a[i];
	for (int i = 0; i < n; ++i)b[i] = 0;
	for (int i = 0; i < n; ++i)c[i] = 0;
	for (int i = 0; i < n; ++i)
	{	
		int k = 0,mark = 0;
		for (int j = i; j < n; ++j)
		{
			for (int t = 0; t < k; ++t)
			{
				if (b[t] == a[j])
				{
					mark = 1;
					k = t;
					for (int e = t; e<n; ++e)
					{
						b[e] = 0;
					}
					b[t] = a[j];
				}
			}
			if (mark == 0)
			{
				k++;
				b[k] = a[j];
			}
			for (int r = 0; r <= k; ++r)
			{
				if (b[r] == i+1)
				{
					c[a[b[r]]]++;
				}
			}
		}
		
	}
	c[a[n-1]-1] = n;
	for (int i = 0, k = 0; k < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (a[j] == a[b[i]])
			{
				a[j] = 0;
			}
		}
		for (int j = 0; j < n; ++j)
		{
			if (a[j] != 0)
			{
				k++;
				if ((a[j]-1)!=a[n-1]-1)
				{
					cout << c[a[j]-1]-1 << ' ';
				}else cout << n << ' ';
				break;
			}
		}
	}
	return 0;
}