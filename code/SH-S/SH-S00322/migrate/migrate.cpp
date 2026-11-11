#include<bits/stdc++.h>
using namespace std;
int f[5005][5005];
int n,t[5005];
void init()
{
	int i,j,k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d %d",&c,&T);
	while(T--)
	{
		long long d,ans=0;
		memset(f,0x3f,sizeof(f));
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&t[i]);
			t[i]+=2500;
		}
		for(int i=1;i<=n;i++)
			f[t[i]][t[i]+d]=1;
		init();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					for(int l=1;l<=n;l++)
						if(f[i][j]==f[k][l])
							ans++;
		printf("%lld",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
