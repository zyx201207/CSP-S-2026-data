#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn;
	int posa,posb;
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i<=m-1;i++)
	{
		maxn=-99999999;
		for(int j = 1;j<n;j++)
		{	
			for(int k =j+1;k<=n;k++)
			{
				if(maxn<(a[j]&a[k]))
				{
					posa=j;
					posb=k;
					maxn=(a[j]&a[k]);
				}
			}
		}
		a[posa]=maxn;
		a[posb]=0;
	}
	cout << maxn;
	return 0;
}
