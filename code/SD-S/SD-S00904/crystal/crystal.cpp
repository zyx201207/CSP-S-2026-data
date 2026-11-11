#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#define ll long long
using namespace std;
const int N=6e5+10;
map<ll,ll> ma;
ll aa[N],n,m,a[N],x,sum[N];
ll maxx=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) 
	{
		scanf("%lld",&a[i]);
		ma[a[i]]++,maxx=max(ma[a[i]],maxx);	
	}
//	n=unique(a+1,a+n+1)-a-1;
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)aa[i]=aa[i-1]+a[i];
	for(ll i=2;i<=n;i++)sum[i]=a[i]*(ll)(i-1)-aa[i-1];
	ll l=1,r=1,ans=0;	
	
	ll tot=0;
	while(l<=n)
	{
		while(r<=n&&sum[r]-sum[l-1]<=m)r++;
		maxx=max(maxx,r-l);
		l++;
//		while(l<=r&&sum[r]-sum[l-1]>m)
	}
	printf("%lld",maxx);
	return 0;
 }
