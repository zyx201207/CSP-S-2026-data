#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		int c[500005] = {};
		int num= 1;
		for(int j = i;j <= n;j++)
		{
			for(int k = 1;k < num;k++)
			{
				if(a[j] == c[k])
				{
					for(int x = k;x <= num;x++)
					{
						c[x] = 0;
					}
					num = k;
					break;
				}
			}
			c[num] = a[j];
			num++;
		}
		for(int j = 1;j <= num;j++)
		{
			b[c[j]]++;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << b[i] << " ";
	}
	return 0;
 } 
