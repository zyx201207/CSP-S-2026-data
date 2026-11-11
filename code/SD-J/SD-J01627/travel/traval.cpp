#include <bits/stdc++.h>
using namespace std;
int n,m,cnt,a[20];
int main()
{
	freopen("traval.in","r",stdin);
	freopen("traval.out","w",stdout);

	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		
	}
	for (int i = 1;i <= 17;i++)
	{
		for (int j = i + 1;i <= 17;j++)
		{
			for (int t = 1;t <= 18;t++)
			{
				for (int r = t + 1;r <= 18;r++)
				{
					if (a[j] == a[i] && a[t] == a[r])
					{
						for (int i = 1;i <= n;i++)
						{
							cout << 1;
							return 0;
						}
					}
					else
					{
						for (int i = 1;i <= n;i++)
						{
							cout << 0;
							return 0;
						}
					}
				}
			}
		}
	}
	return 0; 
}
