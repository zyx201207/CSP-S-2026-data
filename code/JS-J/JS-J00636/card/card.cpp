#include<bits/stdc++.h>
using namespace std;
int a[1005];
int b[1005];
int c[1005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int c1 = 0;
	int c2 = 0;
	for (int o = 1;o <= n;o++)
	{
		for (int i = 0;i <= n;i++)
			c[i] = 0;
		for (int i = o;i <= n;i++)
		{
			c[i] = 1;
			for (int j = 1;j <= i;j++)
			{
				if (a[i] == a[j] && c[i] == 1 && c[j] == 1)
				{
					for (int k = j;k < i;k++)
					{
						c[k] = 0;
					}
				}
			}
		}
		for (int i = 1;i <= n;i++)
		{
			if (c[i] == 1 && a[i] == 1)
			{
				c1++;
				break;
			}
		}
		for (int i = 1;i <= n;i++)
		{
			if (c[i] == 1 && a[i] == 2)
			{
				c2++;
				break;}
		}
	}
	cout << c1 << ' ' << c2 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
