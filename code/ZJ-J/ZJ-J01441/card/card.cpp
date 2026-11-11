#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n + 1];
	int c[m + 1] = {0};
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		int b[n - i + 1] = {0};
		for(int j = i + 1;j <= n;j++)
		{
			for(int k = 1;k <= n - i;k++)
			{
				if(b[k] == a[j])
				{
					for(int r = k + 1;r <= n - i;r++)
					{
						if(b[r] == 0)
						{
							break;
						}
						b[r] = 0;
					}
				}
			    else
			    {
			    	for(int r = 1;r <= n;r++)
			    	{
			    		if(b[r] == 0)
			    		{
			    			b[r] = a[j];
			    			break;
						}
					}
				}
			}
		}
		for(int j = 1;j <= n;j++)
		{
			if(b[j] == 0)
			{
				break;
			}
			for(int r = 1;r <= m;r++)
			{
				if(b[j] == r)
				{
					c[r]++;
				}
			}
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << c[i] << ' ';
	}
	return 0;
}
