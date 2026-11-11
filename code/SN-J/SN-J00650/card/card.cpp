//陈诗韵 西安翱翔中学 SN-J00650
#include<bits/stdc++.h>
using namespace std;
int a[5005],n,m;
int vis[5005],num[5005];
void moni()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=j;k<=n;k++)
			{
				if(a[j]==a[k])
				{
					cnt++;
					vis[j]=1,vis[k]=1;
				}
			}
		}
		for(int j=1;j<=n;j++)if(!vis[j])num[a[j]]++;
		for(int j=1;j<=m;j++)printf("%d ",num[j]);
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n<=500&&m<=200)moni();
	return 0;
}
