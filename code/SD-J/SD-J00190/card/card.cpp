#include <bits/stdc++.h>
using namespace std;

int a[500005];
int ans[300005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++)
	{
		int pz[500005] = {0};
		int now = 1;
		for(int j = i;j<=n;j++)
		{
			int pos = 0;
			for(int k = 1;k<now;k++)
			{
				if(pz[k]==a[j])
				{
					pos = k;
					break;
				}
			}
			if(pos)
			{
				for(int k = pos;k<=now;k++)
				{
					pz[k] = 0;
				}
				now = pos;
			}
			pz[now] = a[j];
			now++;			
		}
		for(int k = 1;k<now;k++)
		{
			ans[pz[k]]++;
		}
	}
	for(int i = 1;i<=m;i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
