//SN-S00468 钟林希 西安翱翔中学 
#include<bits/stdc++.h>
using namespace std;
long long t,n,k,a[1000050],ans,minn,cnt[1000050],f[1000][1000],c;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(int ii=1;ii<=t;ii++)
	{
		ans=0;
		scanf("%lld%lld",&n,&k);
		memset(cnt,0,sizeof cnt);
		memset(f,0,sizeof f);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			minn=min(a[i],minn);
		}
		if(minn<0)
		{
			for(int i=1;i<=n;i++)
			{
				a[i]+=abs(minn);
				cnt[a[i]]++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+k+1;j<=n;j++)
			{
				if(f[i+k][j]==0&&f[i][j-k]==0&&cnt[i+k]!=0&&cnt[j-k]!=0&&i+k!=j-k)
				{
					f[i][j]=2;
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
