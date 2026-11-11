#include<bits/stdc++.h>
#define ll long long
#define pp pair<ll,ll>
const ll N=5e5+1010;
using namespace std;
ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
ll a[N],n,m,ans,l,r,mid,sum[N],cnt;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(ll i=1;i<=n;i++)
	{
		l=1,r=i;cnt=i;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m) r=mid-1,cnt=mid;
			else l=mid+1;
		}
		ans=max(ans,i-cnt+1);
	}
	cout<<ans;
	return 0;
}