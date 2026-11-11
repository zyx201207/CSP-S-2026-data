#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	ll re=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		re=(re<<3)+(re<<1)+c-'0';
		c=getchar();
	}
	return re*f;
}
inline void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
ll n,m;
const int maxn=5e5+5;
ll a[maxn];
ll s[maxn];
ll work(ll l,ll r,ll mi,ll k)
{
	ll re=1;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(mi<=k*mid-s[mid-1])
		{
			r=mid-1;
			re=mid;
		}
		else l=mid+1;
	}
	return re;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	//freopen("crystal4.in","r",stdin);
	//freopen("tst.txt","w",stdout);
	
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	n=read();m=read();
	for(ll i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	ll ans=1;
	for(ll i=n;i>=1;i--)
	{
		ll r=i,l=work(1,i,a[i]*(i+1)-s[i]-m,a[i]);
		ans=max(ans,r-l+1);
	}
	write(ans);
	return 0;
}
/*

dont press F11

seek if need long long

ensure function return

ensure file & extra output





*/
