#include<bits/stdc++.h>
using namespace std;
int a[30005],b[30005],cnt[30005]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		
		for(int j=i;j<=n;j++)
		{
			b[j]=a[j];
			for(int k=1;k<j;k++)
			{
				if(b[j]==b[k])
				{
					for(int x=k;x<=j-1;x++)
					{
						b[x]=0; 
						//cout<<b[x];
					}
				}
				//cout<<b[k]<<" ";
			}
		}
		for(int j=i;j<=n;j++)
		{
			//cout<<b[j]<<" ";
			if(b[j]>=1)cnt[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
