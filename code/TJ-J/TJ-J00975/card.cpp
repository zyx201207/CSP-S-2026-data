#include <bits/stdc++.h>
using namespace std;
int a[300005],b[300005],c[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int x = n;
	bool t = false;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		x = n;
		for(int j = i;j <= x;j++)
		{
			t = false;
			for(int c = 1;c <= x;c++)
			{
				if(b[c] == a[j])
				{
					t = true;
				}
			}
			if(t == false)
			{
				b[j] = a[j];
			}
			else
			{
				for(int v = j;v <= x;v++)
				{
					b[v] = 0;
					for(int g = 1;g <= x;g++)
					{
						if(b[g] == a[j])
						{
							b[g] = 0;
						}
					}
				}
				b[j] = a[j];
			}
		}
		for(int i = 1;i <= n;i++)
		{
			if(b[i] != 0)
			{
				c[i]++;
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		cout << c[i] << " ";
	}
	return 0;
}
