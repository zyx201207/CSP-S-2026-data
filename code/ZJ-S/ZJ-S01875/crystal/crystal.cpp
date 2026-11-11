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

int n,p,p0,ans;

long long m,a[500005],b[500005];

int hf(int l,int r)
{
	if(l==r)return l;
	int mid=(l+r)>>1;
	int k=(p-mid)*a[p]-(b[p-1]-b[mid-1]);
	if(k==m)return mid;
	return (k>m)?hf(mid+1,r):hf(l,mid);
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=_sri32();
	m=_sri64();
	for(int i=1;i<=n;++i)a[i]=_sri64();
	stable_sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)b[i]=b[i-1]+a[i];
	for(p=1;p<=n;++p)
	{
		p0=hf(1,p);
		ans=max(ans,p-p0+1);
	}
	_swi32(ans);
	fclose(stdout);
	return 0;
}
