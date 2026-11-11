#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
ll n,m,a[500009],cnt,l=1,r;
ll read()
{
	ll x=0,f=1;
	char ch=getchar_unlocked();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar_unlocked();
	}
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar_unlocked();
	return x*f;
}
bool check(ll len)
{
	ll s=1e38;
	for(ll i=0;i<=n-len+1;i++)s=min(s,a[i+len-1]-a[i]);
	return s<=m;
}
void print(ll x)
{
	if(x>=10)print(x/10);
	putchar(x%10+48);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(ll i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)a[i]=a[i+1]-a[i];
	n--;
	for(ll i=1;i<=n;i++)a[i]*=i;
	for(ll i=1;i<=n;i++)a[i]+=a[i-1];
	r=n;
	while(l<=r)
	{
		ll m=l+r>>1;
		if(check(m))l=m+1,cnt=m;
		else r=m-1;
	}
	print(cnt);
	return 0;
}