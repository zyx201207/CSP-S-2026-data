#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin>>n>>m;
	int a[n], ans[m], nn = n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(nn>0)
	{
		for(int i = 1;i<=n;i++)
		{
			for(int j = i;j<n;j++)
			{
				if(a[i]==a[j])
				{
					a[j] = a[i];
					i = j;
				}
			}
		}
		for(int i = 1;i<=m;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				if(a[j]==i)
				{
					ans[i]++;
				}
			}
		}
		nn--;
	}
	for(int i = 1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
