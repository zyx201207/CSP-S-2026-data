#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
ll n,m,ans=1,l,r,s[500010],a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	l=1;
	for(int i=2;i<=n;i++)
	{
		while(l<i&&(i-l)*a[i]-(s[i-1]-s[l-1])>m)l++;
		ans=max(ans,i-l+1);
	}
	write(ans);
	return 0;
}
