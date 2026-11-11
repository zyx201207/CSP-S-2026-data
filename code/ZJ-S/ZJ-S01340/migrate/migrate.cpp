#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
	int val=0,k=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') k=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		val=val*10+(ch-'0');
		ch=getchar();
	}
	return val*k;
}
inline void write(int val)
{
	if(val<0) putchar('-'),val=-val;
	if(val>9) write(val/10);
	putchar(val%10+'0');
}
int c,T;
const int maxN=2e6+5;
int n;
long long d,x[maxN];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--)
	{
		int n=read(),d=read();
		for(int i=1;i<=n;i++) x[i]=read();
		if(n<=2)
		{
			puts("0");
			continue;
		}
		bool ckA=true;
		for(int i=2;i<n;i++)
		{
			if(x[i]-x[i-1]!=x[i+1]-x[i])
			{
				ckA=false;
				break;
			}
		}
		if(ckA)
		{
			if(x[2]-x[1]==0)
			{
				puts("0");
				continue;
			}
			long long jump_siz=d/(x[2]-x[1]);
			if(jump_siz==0||jump_siz==1)
			{
				puts("0");
				continue;
			}
			write(max(0ll,n-jump_siz*2+1)),putchar('\n');
			continue;
		}
		puts("0");
	}
	return 0;
}