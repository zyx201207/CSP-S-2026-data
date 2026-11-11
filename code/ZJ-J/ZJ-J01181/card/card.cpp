#include<bits/stdc++.h>
using namespace std;
int a[500005],table[500005],ans[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}for(int i=1;i<=n;i++)
	{
		if(table[a[i]]==0)
		{
			table[a[i]]++;
		}
		else
		{
			table={};
		}
    }
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(table[a[j]]>0)
			{
				ans[i]++;
			}
		}
		cout<<ans[i]<<' ';
	}
	return 0;
}