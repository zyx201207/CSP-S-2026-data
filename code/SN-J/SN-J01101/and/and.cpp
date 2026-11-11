#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn,sum,b = -1;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	maxn = a[1]; 
	for(int i = 0;i < m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			for(int l = 1;l <= n;l++)
			{
				maxn = a[i] & a[l];
			}
			b = max(b,maxn);
		}
	}
	cout << b;
	return 0;
}
