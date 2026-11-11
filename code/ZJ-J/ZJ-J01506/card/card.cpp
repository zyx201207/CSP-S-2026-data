#include<bits/stdc++.h>
using namespace std;
int a[500001]={};
int num[300001]={};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int b[500001]={};
		int t=0;
		for(int j=i;j<=n;j++)
		{
			int g=0;
			for(int k=1;k<=t;k++)
			{
				if(a[j]==b[k])
				{
					g=k;
					break;
				}
			}
			if(g==0)
			{
				t++;
				b[t]=a[j];
			}
			else
			{
				t=g;
			}
		}
		for(int j=1;j<=t;j++)
		{
			num[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",num[i]);
	}
	return 0;
}
