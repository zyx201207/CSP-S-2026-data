#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e6+5;
ll read()
{
	ll ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
		
	while(c>='0'&&c<='9')
	{
		ans=ans*10+c-48;
		c=getchar();
	}
	return ans*f;
}
ll c,T,n,d,a[maxn],dis[maxn],cnt[maxn],sum[maxn],ans;
bool flagA;
void solveA(ll q)
{
	ll x=d/q;
	if(x==0||x==1)
	{
		printf("0\n");
		return;
	}
	ans=max(0ll,n-2*x+1);
	printf("%lld\n",ans);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--)
	{
		ans=0;
		n=read(),d=read();
		for(int i=1;i<=n;i++)
			a[i]=read();
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		flagA=true;
		ll q=a[2]-a[1];
		if(c==11||c==12)
		{
			solveA(q);
			continue;
		}
		for(int i=3;i<=n;i++)
		{
			if(a[i]-a[i-1]!=q)
			{
				flagA=false;
				break;
			}
		}
		if(flagA)
		{
			solveA(q);
			continue;
		}
		if(a[n]-a[1]<=d)
		{
			printf("0\n");
			continue;
		}
		for(int l=1;l<=n;l++)
		{
			for(int r=l-1;r<=n;r++)
				sum[r]=0,dis[r]=1e18,cnt[r]=0;
			dis[l]=0,cnt[l]=1,sum[l]=1;
			ll lst=l,p=1;
			for(int r=l+1;r<=n;r++)
			{
				//cout<<r<<" ";
				if(a[r]-a[lst]<=d)
				{
					dis[r]=p;
					ll pos1=lower_bound(a+l,a+n+1,a[r]-d)-a;
					ll pos2=lower_bound(dis+l,dis+r+1,dis[r]-1)-dis;
					ll pos3=lower_bound(dis+l,dis+r+1,dis[r])-dis;
					//cout<<pos1<<"|"<<pos2<<" "<<pos3<<"\n";
					cnt[r]=sum[min(pos3,1ll*r)-1]-sum[max(pos1,pos2)-1];
					sum[r]=sum[r-1]+cnt[r];
				}
				else
				{
					lst=r-1;
					p++;
					if(a[r]-a[lst]>d)
						break;
					else
					{
						dis[r]=p;
					ll pos1=lower_bound(a+l,a+n+1,a[r]-d)-a;
					ll pos2=lower_bound(dis+l,dis+r+1,dis[r]-1)-dis;
					ll pos3=lower_bound(dis+l,dis+r+1,dis[r])-dis;
					//cout<<pos1<<"|"<<pos2<<" "<<pos3<<"\n";
					cnt[r]=sum[min(pos3,1ll*r)-1]-sum[max(pos1,pos2)-1];
					sum[r]=sum[r-1]+cnt[r];
					}		
				}
			}
			/*
			lst=l,p=1;
			for(int r=l-1;r>=1;r--)
			{
				if(a[lst]-a[r]<=d)
					dis[l][r]=p;
				else
				{
					lst=r+1;
					p++;
					if(a[lst]-a[r]>d)
						break;
					else
						dis[l][r]=p;
				}
			}*/
			for(int r=l;r<=n;r++)
			{
				if(cnt[r]==2)	ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
 } //17:04 ~48pts
