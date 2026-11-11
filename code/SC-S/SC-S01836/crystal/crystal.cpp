#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return f*x;
}
int n,m;
int a[500010];
int s[500010];
bool check(int x)
{
	bool bol=false;
	for(int i=x;i<=n;++i)
		if(a[i]*(x-1)-s[i-1]+s[i-x]<=m)
			bol=true;
	return bol;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
		s[i]=s[i-1]+a[i];
	int l=1,r=n,mid,ans=1;
	while(l<=r)
	{
		mid=l+(r-l)/2;
		if(check(mid)==true)
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}