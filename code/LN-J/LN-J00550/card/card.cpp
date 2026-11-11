#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in", "w", stdin);
	freopen("card.out", "r", stdout);
	int n, m, a[500005], x = 1, b[500005] = {0}, c[500005] = {0};
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = i;j<=n;j++)
		{
			bool flag = 1;
			for(int k = 1;k<=x;k++)
			{
				if(b[k]==a[j])
				{
					flag = 0;
				}
			}
			if(flag==1)
			{
				b[x++] = a[j];
			}
			else
			{
				while(b[x-1]!=a[j])
				{
					x--;
				}
			}
		}
		for(int j = 1;j<=x;j++)
		{
			c[b[j]]++;
			b[j] = 0;
		}
	}
	for(int i = 1;i<=m;i++)
	{
		cout << c[i] << ' ';
	}
	return 0;
}            
