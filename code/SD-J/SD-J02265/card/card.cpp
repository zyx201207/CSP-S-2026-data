#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005];
bool f[500005],t[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)f[j]=false;
		for(int j=1;j<=m;j++)t[j]=false;
		for(int j=i;j<=n;j++)//ÒÀ´Î´òÅÆ 
		{
			for(int k=i;k<j;k++)
			{
				if(f[k])continue;
				if(a[k]==a[j])
				{
					for(int x=k;x<j;x++)f[x]=true;
				}
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(!f[j]&&!t[a[j]])
			{
				ans[a[j]]++;
				t[a[j]]=true;
			}
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}
