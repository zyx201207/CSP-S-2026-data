#include<bits/stdc++.h>
using namespace std;
long long w[500005];
long long f[505][505];
vector<long long> hvr[500005],lgh[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long tshinf,n,m,d,q;
	scanf("%lld %lld %lld %lld %lld",&tshinf,&n,&m,&d,&q);
	for(long long i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(long long i=1;i<=n;i++)
	{
		long long k;
		scanf("%lld",&k);
		for(long long j=1;j<=k;j++)
		{
			long long a,t;
			scanf("%lld %lld",&a,&t);
			hvr[a].push_back(i);
			lgh[a].push_back(t);
		}
	}
	memset(f,0x3f,sizeof(f));
	for(long long i=1;i<=m;i++)
	{
		for(long long j=0;j<hvr[i].size();j++)
			for(long long k=j+1;k<hvr[i].size();k++)
			{
				f[hvr[i][j]][hvr[i][k]]=f[hvr[i][k]][hvr[i][j]]=min(f[hvr[i][j]][hvr[i][k]],lgh[i][j]+lgh[i][k]);
			}
	}
/*	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("(%d) ",f[i][j]);
		printf("\n");
	}*/
	for(long long i=1;i<=n;i++)
		f[i][i]=0;
	for(long long k=1;k<=n;k++)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<=n;j++)
			{
				if(f[i][k]+f[k][j]<f[i][j])
					f[i][j]=f[i][k]+f[k][j];
			}
		}
	}
	for(long long i=1;i<=q;i++)
	{
		long long a,b;
		scanf("%lld %lld",&a,&b);
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(long long j=0;j<hvr[a].size();j++)
			for(long long k=0;k<hvr[b].size();k++)
			{
		//		printf("**%d %d %d %d %d\n",hvr[a][j],hvr[b][k],f[hvr[a][j]][hvr[b][k]],lgh[a][j],lgh[b][k]);
       				ans=min(ans,f[hvr[a][j]][hvr[b][k]]+lgh[a][j]+lgh[b][k]);				
			}
		printf("%lld\n",ans+w[a]+w[b]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
