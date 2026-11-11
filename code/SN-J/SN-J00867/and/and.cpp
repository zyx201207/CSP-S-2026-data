#include<bits/stdc++.h>
using namespace std;
int n,m,a[2005],maxn;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int cnt = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(m == 2)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				maxn = max((a[i] & a[j]),maxn);
			}
		}
	}
	if(m == 3)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				for(int k = j + 1;k <= n;k++)
				{
					maxn = max((a[i] & a[j] & a[k]),maxn);
				}

			}
		}
	}
	cout << maxn << endl;
	return 0;
}
