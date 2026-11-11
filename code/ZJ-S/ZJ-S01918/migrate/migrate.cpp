#include <bits/stdc++.h>
using namespace std;
int c,t,n,cnt,now;
long long d,x[2000005],a[2000005],ans;
bool b[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c<=10)
	{
		while(t--)
		{
			scanf("%d%lld",&n,&d);
			ans=0;
			for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
			sort(x+1,x+n+1);
			for(int i=1;i<n-2;i++)
			{
				cnt=0;
				now=1;
				a[0]=i;
				while(x[a[cnt]]<=x[n])
				{
					a[cnt+1]=(d<=x[n]-x[a[cnt]]?upper_bound(x+a[cnt],x+n+1,x[a[cnt]]+d)-x-1:n);
					cnt++;
					if(a[cnt]==a[cnt-1])break;
					if(cnt==1)continue;
					int r=(x[a[cnt]]-x[1]>=d?lower_bound(x+a[cnt-2]+1,x+a[cnt-1]+1,x[a[cnt]]-d)-x:1);
					b[cnt]=b[cnt-1];
					if(r<a[cnt-1])
					{
						if(b[cnt]||a[cnt-1]-r>1)break;
						else if(cnt>2)
						{
							r=(x[r]-x[1]>=d?lower_bound(x+a[cnt-3]+1,x+a[cnt-2]+1,x[r]-d)-x:1);
							if(r<a[cnt-2])break;
						}
						b[cnt]=1;
					}
				}
				cnt--;
				if(cnt<=1)continue;
				for(int j=a[1]+1;j<=n;j++)
				{
					if(j==a[now+1])
					{
						ans+=b[++now];
						if(now==cnt)break;
						continue;
					}
					int r=(x[j]-x[1]>=d?lower_bound(x+a[now-1]+1,x+a[now]+1,x[j]-d)-x:1);
					if(r<a[now])
					{
						if(b[now]||a[now]-r>1)continue;
						if(now==1)
						{
							ans++;
							continue;
						}
						r=(x[r]-x[1]>=d?lower_bound(x+a[now-2]+1,x+a[now-1]+1,x[r]-d)-x:1);
						if(r==a[now-1])ans++;
					}
					else if(b[now])ans++;
				}
			}
			printf("%lld\n",ans);
		}
	}
	else if(c==11||c==12)
	{
		while(t--)
		{
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
			long long k=d/abs(x[2]-x[1]);
			if(k<=1)printf("0\n");
			else printf("%d\n",max(n-2*k+1,0*1ll));
		}
	}
	return 0;
}