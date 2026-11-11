#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
const int N=2e6+10;
int ans[N],tt[N],sum[N],c,t,n,d,a[N];
void check(int aa)
{
	int mm=d/aa;
	if(mm==1){printf("0\n");return;}
	mm++;
	if(mm>=4)printf("0\n");
	else printf("%lld\n",n-mm);
	return;
}
void dfs(int fa,int x,int cnt,int ans)
{
	if(cnt>d)return;
	for(int i=x+1;i<=n;i++)
	{
		if(cnt+sum[i]-sum[x-1]>d)tt[ans]++;
		dfs(fa,i,cnt+sum[i]-sum[x-1],ans+1);
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{	
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i];
		int aa=a[2]-a[1],f=0;
		for(int i=3;i<=n;i++)
		{
			if(a[i]-a[i-1]!=aa){f=1;break;}
		}
		if(!f){check(aa);continue;}
		int xx=1,maxx=0;
		for(int i=1;i<=n;i++)
		{
			memset(ans,0,sizeof(ans));
			if(a[n]-a[i]>d)
				dfs(i,i,0,0);//从第i个数开始枚举以i为起点只有两种方案的 
			for(int i=1;i<=n;i++)if(ans[i]==2)maxx++;
			else break;
		}
		printf("%lld\n",maxx);
	}
	return 0;
}

