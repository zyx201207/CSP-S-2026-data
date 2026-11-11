#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;
ll n,m,a[500010];
ll cnt;
inline bool check(int x)  
{
	int sum=0;
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=x)
		{
			sum+=x-a[i];
			cnt++;	
		}	
	}	
	return sum<=m;
} 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll mx=-2e18,mi=2e18;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),mx=max(mx,a[i]),mi=min(mi,a[i]);
	sort(a+1,a+n+1);
	if(n>5000)
	{
		int gc=a[2]-a[1];
		int ct=m/gc;
		int cn=1;
		for(int i=2;i<=n;i++)
		{
			if(ct-(i-1)>0)
			{
				cn++;
				ct-=(i-1);
			}
		}
		printf("%lld\n",cn);
	}
	ll l=mi,r=mx,ans=-2e18;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(check(mid))
		{
			l=mid+1;
			ans=max(ans,cnt);
		}
		else 
		{
			r=mid-1;
		}
	}
	printf("%lld\n",ans);
	return 0;	
} 
/*
5 5 
1 2 4 8 9

*/
