#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],t[200005],c[200005],sum[200005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=200001;j++)
		{
			c[j]=0;
			b[j]=0;
			t[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(t[a[j]]!=0&&c[j]==0)
			{
				for(int k=t[a[j]];k<=j-1;k++)
				{
					if(c[k]==0)
					{
						b[a[k]]--;
						c[k]=1;
					}
				}
			}
			b[a[j]]++;
			t[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
		{
			if(b[j]>0)
				sum[j]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}
