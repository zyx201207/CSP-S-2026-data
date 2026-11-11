#include <bits/stdc++.h>
using namespace std;
#ifdef __unix__
#define getchar getchar_unlocked
#else
#define getchar _getchar_nolock
#endif
inline long long read()
{
	long long x=0,f=1;
	char c=getchar();
	while((c<'0')||(c>'9')){if(c=='-')f*=-1ll;c=getchar();}
	while((c>='0')&&(c<='9')){x=x*10ll+(long long)(c-'0');c=getchar();}
	return x*f;
}
long long a[500500],s[500500];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,mx=0,k,l,r,h;
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		k=i;
		l=0;
		r=i;
		for(;;)
		{
			if((l+1)>=r)
			{
				break;
			}
			h=(l+r)/2;
			if((a[i]*(i-h+1)-(s[i]-s[h-1]))<=m)
			{
				r=h;
				k=h;
			}
			else
			{
				l=h;
			}
		}
		mx=max(mx,(i-k+1));
	}
	cout<<mx;
	return 0;
}
