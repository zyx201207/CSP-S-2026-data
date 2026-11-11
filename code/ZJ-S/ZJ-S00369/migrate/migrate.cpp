#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll n,d,c,T,x[N],md[N],num[N];
__int128 sum[N];
int ld[N],rmd[N];
ll solve(ll n)
{
	ll ans=0;	
		for(int s=1;s<n;s++)
		{
			for(int i=1;i<=n;i++)
			{
				num[i]=sum[i]=md[i]=0;
			}	
			for(int i=s;i<=n;i++)
			{
				int l=s,r=i,mid,an=-1;
				while(l<=r)
				{
					mid=(l+r)>>1;
					if(x[i]-x[mid]<=d)
					{
						an=mid;
						r=mid-1;
					}
					else l=mid+1;
				}
				if(an==i) md[i]=0;
				else md[i]=md[an]+1;
				ld[i]=an;rmd[md[i]]=i;
			}
			num[s]=1;sum[s]=num[s];sum[s-1]=0;
			for(int i=s+1;i<=n;i++)
			{
				if(md[i]==0)
				{
					num[i]=1;
					continue;
				}
				num[i]=sum[min(rmd[md[i]-1],i-1)]-sum[ld[i]-1];
				sum[i]=sum[i-1]+num[i];
				if(num[i]==2) ans++;
				if(num[min(rmd[md[i]-1],i-1)]>2&&num[ld[i]-1]>2) break;
			}
		}
	return ans;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		scanf("%lld%lld",&n,&d);
		ll cnt=0,ans=0,xx;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&xx);
			if(cnt!=0&&xx-x[cnt]>d)
			{
				ans+=solve(cnt);
				cnt=0;
			}
			x[++cnt]=xx;
		}
		if(cnt>0) ans+=solve(cnt);
		printf("%lld\n",ans);
	}
	return 0;
}