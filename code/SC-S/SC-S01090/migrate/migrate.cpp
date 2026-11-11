#include<bits/stdc++.h>
using namespace std;
long long a[2000005],vis[200005],d[5005][5005],cnt[5005][5005];
long long n,dis;
struct g{
	long long to,next_;
}edge[20000005];
long long tot,head[200005];
void add(long long x,long long y)
{
	edge[++tot].to=y;
	edge[tot].next_=head[x];
	head[x]=tot;
}
priority_queue<pair<long long,long long> > q;
void dij(long long s)
{
	for(long long i=1;i<=n;i++)
	{
		d[s][i]=(long long)1<<60;
		vis[i]=0;
	}
	d[s][s]=0;
	cnt[s][s]=1;
	q.push({0,s});
	while(q.size())
	{
		long long x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(long long i=head[x];i;i=edge[i].next_)
		{
			long long y=edge[i].to;
			if(vis[y]) continue;
			if(d[s][y]==d[s][x]+1)
			{
				cnt[s][y]+=cnt[s][x];
			}
			if(d[s][y]>d[s][x]+1)
			{
				d[s][y]=d[s][x]+1;
				q.push({-d[s][y],y});
				cnt[s][y]=cnt[s][x];
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long C,T;
	scanf("%lld%lld",&C,&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&dis);
		int flag=0;
		long long ch,fa;
		for(long long i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) flag=1;
		}
		ch=a[n]-a[n-1];
		fa=a[n]-a[1];
		if(n<=5000)
		{
			long long ans=0;
			for(long long i=1;i<=n;i++)
			{
				for(long long j=i+1;j<=n;j++)
				{
					if(a[j]-a[i]<=dis)
					{
						add(i,j);
						add(j,i);
					}
				}
			}
			for(long long i=1;i<=n;i++)
			{
				dij(i);
				for(long long j=i;j<=n;j++)
				{
					if(cnt[i][j]==2) ans++;
				}
			}
			for(long long i=1;i<=n;i++)
			{
				head[i]=0;
				for(long long j=1;j<=n;j++)
				{
					d[i][j]=0;
					cnt[i][j]=0;
				}
			}
			tot=0;
			printf("%lld\n",ans);
			continue;
		}
		if(!flag)
		{
			long long jia=dis/ch;
			if(jia==1||n==1||ch>dis||fa<=dis)
			{
				printf("0\n");
				continue;
			}
			long long ans=n-(long long)2*jia+1;
			printf("%lld\n",ans);
			continue;
		}
		printf("0\n");
	}
	return 0;
}