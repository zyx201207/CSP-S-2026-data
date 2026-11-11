#include<bits/stdc++.h>
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
#define int long long
#define code using
#define by namespace
#define plh std
code by plh;
namespace fastio
{
	int read()
	{
		int z=0,f=1;
		char c=getchar();
		while(c<'0'||c>'9')
		{
			if(c=='-')
			{
				f=-1;
			}
			c=getchar();
		}
		while(c>='0'&&c<='9')
		{
			z=z*10+c-'0';
			c=getchar();
		}
		return z*f;
	}
	void write(int x)
	{
		if(x<0)
		{
			putchar('-');
			x=-x;
		}
		static int top=0,stk[106];
		while(x)
		{
			stk[++top]=x%10;
			x/=10;
		}
		if(!top)
		{
			stk[++top]=0;
		}
		while(top)
		{
			putchar(char(stk[top--]+'0'));
		}
	}
	void read(int *st,int *ed)
	{
		for(;st!=ed;st++)
		{
			(*st)=read();
		}
	}
	void write(int *st,int *ed)
	{
		for(;st!=ed;st++)
		{
			write(*st);
			putchar(' ');
		}
	}
}
using namespace fastio;
const int N=5e5+6;
int n,m,a[N],s[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	read(a+1,a+n+1);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	for(int l=1,r=1;r<=n;r++)
	{
		while(a[r]*(r-l+1)-(s[r]-s[l-1])>m)
		{
			l++;
		}
		ans=max(ans,r-l+1);
	}
	write(ans);
	return 0;
}