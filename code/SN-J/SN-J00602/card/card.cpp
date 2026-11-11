#include <bits/stdc++.h>
using namespace std;
long long a[50005],n,m,b[50005],t[50005],y = 1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	while(y <= n)
	{
		
		for(int i = y ;i <= n;i++)
		{
			for(int j = y;j <= i;j++)
			{
				if(a[i] == a[j] && i != j)
				{
					for(int x = j;x < i;x++)
					{
						a[x] = 0;
					}
				}
			}
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = y;j <= n;j++)
			{
				if(a[j] == i)
				{
					t[i]++;
				}
			}
		}
		for(int i = y;i <= n;i++)
		{
			a[i] = b[i];
		}
		y++;
	}
	for(int i = 1;i <= m;i++)
	{
		cout << t[i] << " ";
	}
}
