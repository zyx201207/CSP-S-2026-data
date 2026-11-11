#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d,a[200005],sum[200005];
void dfs(long long st,long long ed,long long k)
{
	if(st<=ed)
	{
		if(st==ed)sum[k]++;
		for(long long i=st+1;i<=ed;i++)
		if(a[i]-a[st]<=d)dfs(i,ed,k+1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(long long k=1;k<=t;k++)
	{
		long long q=0,Min=3*1e18;
		scanf("%lld%lld",&n,&d);
		for(long long i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(i>1)Min=min(Min,a[i]-a[i-1]);
		}
		if(Min>d/2)
		printf("0\n");
		else
		{
			for(long long i=1;i<=n-3;i++)
			for(long long j=i+3;j<=n;j++)
			{
				memset(sum,0,sizeof(sum));
				dfs(i,j,0);
				for(long long l=1;l<=n;l++)
				if(sum[l]!=0)
				{
					q+=(sum[l]==2);
					break;
				}
			}
			printf("%lld\n",q);
		}
	}
}