#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[500005],b[300005];
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		b[a[i]] += i;
	}
	for(int i = 1;i <= n;i++)
	{
		for (int j = i;j <= n;j++)
		{
			for (int k = i;k < j;k++)
			{
				if(a[k] == a[j])
				{
					for (int l = k;l <= j;l++)
					{
						b[a[l]]--;
					}
				}
			}
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout << b[i];
	}
	return 0;
}
