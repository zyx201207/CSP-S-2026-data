#include<bits/stdc++.h>
using namespace std;
int c,t;
int x[2000005],f[2000005][2000005],n,d,ans,wz;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int op=1;op<=t;op++)
	{
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
			 x[i]=0;
		ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&x[i]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=0;
		for(int i=1;i<=n;i++)
				f[i][i+1]=1;
		for(int i=n;i>=1;i--)
			for(int j=i;j<=n;j++)
			{
				if(j-i>=d)
				{
					for(int k=1;k<=d;k++)
					{
						f[i][j]=min(f[i][j],f[i][j-k]+f[j-k][j]);
						wz=f[i][j];
					}
				}
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=0;
		for(int i=1;i<=n;i++)
				f[i][i+1]=1;
		for(int i=n;i>=1;i--)
		{
			for(int j=i;j<=n;j++)
			{
				if(j-i>=d)
				{
					for(int k=1;k<=d;k++)
					{
						f[i][j]=min(f[i][j],f[i][j-k]+f[j-k][j]);
						if(f[i][j]==wz)
						{
							ans++;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
