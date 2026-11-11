#include <bits/stdc++.h>
using namespace std;
const int N=1e6+6;	
typedef long long ll;
ll a[N],b[N]; 
inline ll read()
{
	ll o=0,p=1;
	char c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-')
		{
			p=-1;
		}
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		o=o*10+c-'0';
		c=getchar();
	}
	return o*p;
}
inline void write(ll d)
{
	if (d<0)
	{
		putchar('-');
		d=-d;
	}
	if (d>9)
	{
		write(d/10);
		d=d%10;
	}
	putchar(d+'0');
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	
	c=read();
	t=read();
	if (c==13||c==14)
	{
		while (t--)
		{
			ll n,d;
			n=read();
			d=read();
			for (ll i = 1;i <= n;i++)
			{
				a[i]=read();
			}
			if (a[3]-a[1]>d)
			{
				write(0);
				printf("\n");
			}
			else
			{
				ll m=d/(a[3]-a[1]);
				printf("%lld",(ll)(n-m-1));
			}
		}
		return 0;
	}
/*	while (t--)
	{
		ll n;
		n=read();
		for (ll i = 1;i <= n;i++)
		{
			x[i]=read();
		}
		for (ll i = 1;i < n-1;i++)
		{
			if (x[i+2]-x[i]<=d)
			{
				b[++cnt]=i;
			}
		}
		for (ll i = 1;i <= n;i++)
		{
			for (ll j = 1;j <= n;j++)
			{
				
			}
		}
	}*/ 
	return 0;
}

