#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
#define double long double
#define unsigned unsigned int
using namespace std;
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;
int n,m,ans,a[500005];
int read()
{
	int x=0,op=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')op=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*op;
}
void write(int x)
{
	if(x<0)
	{
		x*=-1;
		putchar('-');
	}
	if(x>=10)write(x/10);
	putchar(x%10+'0');
	return;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);
	for(int i=n,j=n;i>=1;i--)
	{
		while(j>1&&m-(a[i]-a[j-1])>=0)
			j--,m-=(a[i]-a[j]);
		ans=max(ans,i-j+1);
		m+=(a[i]-a[i-1])*(i-j);
	}
	write(ans);
	return 0;
}
