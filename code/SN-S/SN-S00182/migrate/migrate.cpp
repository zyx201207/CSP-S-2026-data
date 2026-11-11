#include<cstdio>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,T,n,pre[N],nxt[N],cnt[N],fl[N],p[N];
ll d,a[N],sum,c1[N],g[N],f[N][2];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
//	T=1;
	while(T--)
	{
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			f[i][0]=f[i][1]=cnt[i]=c1[i]=g[i]=fl[i]=p[i]=0;
		}
//		if(T!=10) continue;
		int p1=1,p2=1;
		for(int i=1;i<=n;i++)
		{
			while(p1<i&&a[i]-a[p1]>d) p1++;
			while(p2<n&&a[p2+1]-a[i]<=d) p2++;
			pre[i]=p1,nxt[i]=p2;
//			if(nxt[i]==i) printf("%d ",i);
//			printf("a%d %d %lld %lld\n",i,nxt[i],d,a[i]-a[i-1]);
			cnt[p1]++;
		}
		for(int i=n;i>0;i--)
		{
			c1[i]+=cnt[i]+(pre[i]!=i);
			if(pre[nxt[i]]==i&&nxt[i]!=i) c1[i]--;
			if(pre[i]!=i&&nxt[pre[i]]==i) c1[pre[i]]+=c1[i];
		}
		sum=0;
		int tmp=0;
		for(int i=n;i>0;i--)
		{
			int x=nxt[i],y=nxt[nxt[i]];
			if(i!=x) f[i][0]+=f[x][0],f[i][1]=f[x][1];
			f[i][0]+=x-i+(x==i);
//			printf("a%d %d\n",x,y);
			if(x==y) continue;
			if(pre[y]!=x)
			{
				f[i][0]-=f[y][0],f[i][1]-=f[y][1]-p[x];
				p[i]+=f[y][1]-p[x];
				if(pre[y]==x-1)
				{
					f[i][1]+=c1[y],g[i]+=c1[y];
				}
			}
			if(x!=i+1&&y!=x+1&&pre[y-1]!=x)
			{
				f[i][1]-=g[x],fl[i]=1,p[i]+=g[x];
			}
			f[i][0]-=y-x-1;
			f[i][0]+=cnt[x]-(pre[y]==x);
			if(x!=i+1)
			{
				f[i][1]+=cnt[x-1]-(pre[y]==x-1);
				g[i]+=cnt[x-1]-(pre[y]==x-1);
			}
			sum+=f[i][1];
//			if(tmp<=100)
//			printf("%d %d %d %d %d\n",i,f[i][0],f[i][1],x,nxt[i]),tmp++;
		}
		printf("%lld\n",sum);
	}
	return 0;
} 
