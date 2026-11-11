#include<bits/stdc++.h>
using namespace std;
const long long maxn=2e6+5;
long long c,m,T,i,n,l,r,mid,s1,s2,s3,s4,s5,s6,k,de,ans,tmp,d,j;
long long a[maxn],f[maxn],g[maxn];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&T);
	while(T--)
	{
		ans=0;
		scanf("%lld %lld",&n,&d);
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(n==1)
		{
			puts("0");
			continue;
		}
		if(c==11 || c==12)
		{
			de=a[2]-a[1];
			if(2*de>d)
			{
				puts("0");
				continue;
			}
			k=d/de;//i->i+k
			if(n+1-2*k<0) puts("0");
			else printf("%lld\n",n+1-2*k);
			continue;
		}
		for(i=1;i<=n;i++)
		{
			l=i,r=n,tmp=i;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if(a[mid]-d<=a[i]) tmp=mid,l=mid+1;
				else r=mid-1;
			}
			f[i]=tmp;//右侧最远可到达
			l=1,r=i,tmp=i;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if(a[mid]+d>=a[i]) tmp=mid,r=mid-1;
				else l=mid+1;
			}
			g[i]=tmp;//左侧最远可到达
		}
		if(c==13 || c==14)
		{
			for(i=1;i<n;i++)//starter
			{
				s1=f[i];
				s2=s1-1;
				if(s2==i || s2==i-1) continue;
				s3=f[s2];
				s4=f[s2-1];
				if(s3>s4) ans+=(s3-s4);
			}
			printf("%lld\n",ans);
			continue;
		}
	}
	return 0;
}