#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005],ans[300005];
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int j=1;j<=n;j++)
	{
		for (int i=j;i<=n;i++)
		{
			for (int k=i+1;k<n;i++)
			{
				if(a[i]==a[k]);
				for(int q=i;q<k;q++)
				{
					a[q]=0;
				} 
			}
		}
		for (int i=1;i<=n;i++)
		{
			for(int k=1;k<=n;k++)
			{
				if(a[i]=k)
				{
					ans[k]++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout << ans[i];
	}
	return 0;
 } 
