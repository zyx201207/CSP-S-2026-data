#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=2e6+10;
const ll INF=0xfffffffffffffff;
int c,t;
ll n,d,x[maxn],ans;
struct land
{
	long long dis[maxn],kk[maxn];
}f[maxn];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--)
	{
		scanf("%d %d",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%d",&x[i]);
		if(c==11||c==12)
		{
			ans=(n-1)*n/2;
			printf("%lld",ans);
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i-1;j++)f[i].dis[j]=INF,f[i].kk[j]=0;
			if(i>=2)f[i].dis[i-1]=1,f[i].kk[i-1]=1;
			for(int k=i-2;k>=1;k--)
			{
				if(x[i]-x[k]<=d)f[i].dis[k]=1,f[i].kk[k]=1;
				for(int j=i-1;x[i]-x[j]<=d&&j>k;j--)
				{
//					printf("%d %d %d\n",i,j,k);
					if(f[j].kk[k]>=2)continue;
					if(f[j].dis[k]+1<f[i].dis[k])f[i].dis[k]=f[j].dis[k]+1,f[i].kk[k]=1;
					if(f[j].dis[k]+1==f[i].dis[k])f[i].kk[k]++;
				}
				printf("%d\n",f[i].kk[k]);
			}
			for(int j=1;j<=i-1;j++)if(f[i].kk[j]==2)ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}//I give up T3
