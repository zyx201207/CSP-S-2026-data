#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
void print(ll x)
{
	if(x>=10)print(x/10);
	putchar(x%10+48);
}
ll x[2000003];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while(t--)
	{
		if(c==13||c==14)
		{
			ll n=read(),d=read(),cnt1=0,cnt2,res=0;
			for(int i=1;i<=n;i++)x[i]=read();
			sort(x+1,x+n+1);
			for(int i=1;i<=n;i++)
				if(x[i]-x[1]<=d&&x[n]-x[i]<=d){cnt1=i;break;}
			for(int i=n;i>=1;i--)
				if(x[i]-x[1]<=d&&x[n]-x[i]<=d){cnt2=i;break;}
			for(int i=cnt1;i<=cnt2;i++)
				if(i==4||i==n-3)res++;
			printf("%lld\n",res);
		}
		else
		{
			ll n=read(),d=read(),res=0;
			for(int i=1;i<=n;i++)x[i]=read();
			sort(x+1,x+n+1);
			ll p=a[2]-a[1];
			if(d<2*p)puts("0");
			else if(d<3*p)
			printf("%lld\n",max(0ll,n-3));
			else puts("0");
		}
	}
	return 0;
}