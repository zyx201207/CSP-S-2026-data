#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[500001],b[500001],l=1,r,num[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		l = 1;
		r = 0;
		for (int j = i; j <= n; j++)
		{
			for (int k = r; k >= l; k--)
			{
				if (b[k] == a[j])
				{
					r = k-1;
					break;
				}
			}
			b[++r] = a[j];
		}
		for (int j = l; j <= r; j++)
		{
			num[b[j]]++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << num[i] << " ";
	}
	return 0;
}
