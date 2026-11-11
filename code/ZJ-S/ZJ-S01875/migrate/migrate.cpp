#include<bits/stdc++.h>
using namespace std;

char inc;

int ini32x;

bool signf;

inline int _sri32()
{
	inc=getchar();
	if(inc=='-')
	{
		signf=true;
		inc=getchar();
	}
	else signf=false;
	ini32x=0;
	while(isdigit(inc))
	{
		ini32x=(ini32x<<3)+(ini32x<<1)+(inc^0x30);
		inc=getchar();
	}
	return signf?-ini32x:ini32x;
}

inline void _swui32(unsigned int x)
{
	if(x>9u)_swui32(x/10u);
	putchar((x%10u)^0x30);
}

inline void _swi32(int x)
{
	(x<0)?putchar('-'),_swui32(-x):_swui32(x);
}

long long ini64x;

inline long long _sri64()
{
	inc=getchar();
	if(inc=='-')
	{
		signf=true;
		inc=getchar();
	}
	else signf=false;
	ini64x=0ll;
	while(isdigit(inc))
	{
		ini64x=(ini64x<<3ll)+(ini64x<<1ll)+(inc^0x30);
		inc=getchar();
	}
	return signf?-ini64x:ini64x;
}

inline void _swui64(unsigned long long x)
{
	if(x>9ull)_swui64(x/10ull);
	putchar((x%10ull)^0x30);
}

inline void _swi64(long long x)
{
	(x<0ll)?putchar('-'),_swui64(-x):_swui64(x);
}

int c,t,n;

long long d,ans,x[2000005],p[200005];

int _m(int i)
{
	if(d>n)return n;
	return min(i+(int)d,n);
}

void solve()
{
	n=_sri32();
	d=_sri64();
	ans=0;
	for(int i=1;i<=n;++i)x[i]=_sri64();
	for(int i=1;i<=n;++i)p[i]=upper_bound(x+i,x+_m(i),x[i]+d)-x-1-i;
	
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	c=_sri32();
	t=_sri32();
	while(t--)solve();
	
	fclose(stdout);
	return 0;
}

