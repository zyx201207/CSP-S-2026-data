#include <bits/stdc++.h>
using namespace std;

int n,m,a[500005],cnt,nowd[500005],t[500005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++)
	{
		cnt = 0;
		for(int j = i;j<=n;j++)
		{
			bool flag = 1;
			int pos;
			for(int k = 1;k<=cnt;k++)
			{
				if(nowd[k] == a[j])
				{
					flag = 0;
					pos = k;
				}
			}
			if(flag == 1)
			{
				nowd[++cnt] = a[j];
			}
			else
			{
				for(int k = pos;k<=cnt;k++)
				{
					nowd[k] = 0;
					cnt--;
				}
				nowd[cnt] = a[j];
			}
		}
		for(int k = 1;k<=cnt;k++)
		{
			t[nowd[k]]++;
		}
	}
	for(int i = 1;i<=m;i++)
	{
		cout << t[i] << " ";
	}
	
	return 0;
}
