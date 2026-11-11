#include<bits/stdc++.h>
using namespace std;
int a[500005];
int wo[500005];
int ans[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w".stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int len = 0;
	for(int i = 1;i <= n;i++)
	{
		len = 0;
		for(int j = i;j <= n;j++)
		{
			bool flag = 1;
			for(int k = 1;k <= len;k++)
			{
				if(wo[k] == a[j])
				{
					len = k;
					flag = 0;
					break;
				}
			}
			if(flag)
			{
				len++;
				wo[len] = a[j];
			}
		}
		for(int j = 1;j <= len;j++)
		{
			ans[wo[j]]++;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << ans[i] << ' ';
	}
} 
