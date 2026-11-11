#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
		int cnt[500010]={};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int T=n;
	for(int i=1;i<=n;i++)
	{
		int b[500010]={};
		for(int j=i;j<=n;j++) b[j]=a[j];
		for(int j=i;j<=n;j++)
		{
			for(int k=i;k<j;k++)
			{
				if(b[k]==b[j])
				{
					for(int q=k;q<j;q++)
					{
						b[q]=-1;
					}
					break;
				}
			}
		}
		for(int j=n;j>=i;j--)
		{
			if(b[j]==-1) continue;
			else
			{
				cnt[b[j]]++;
				break;
			}
		}
	}
	for(int i=0;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}

