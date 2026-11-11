#include <bits/stdc++.h>
using namespace std;
int n,m;
int maxn = -1;
int maxa = -1;
const int MAXN = 1e5 + 5;
int a[MAXN];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	if(m == 1)
	{
		for(int i = 1 ; i <= n ; i++)
		{
			if(a[i] > maxn)
			{
				maxn = a[i];
			}
		}
		cout << maxn;
		return 0;
	}
	else if(m == n)
	{
		for(int i = 1 ; i <= n ; i++)
		{
			a[i + 1] = a[i] & a[i + 1];
		}
		cout << a[n];
		return 0;
	}
	else if(m == 2)
	{
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = i + 1 ; j <= n ; j++)
			{
				if(a[i] & a[j] > maxa)
				{
					maxa = a[i] & a[j];
				}
			}
		}
		cout << maxa;
		return 0;
	}
	return 0;
}
