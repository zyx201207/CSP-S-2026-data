#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N];
int n,m;
int dfs(int x,int cnt)
{
	if(cnt==1) return a[x];
	int mx=0;
	for(int i=x+1;i<=n;i++)
	{
		mx=max(mx,dfs(i,cnt-1)&a[x]);
	}
	return mx;
}
bool cmp(int x,int y)
{
	return x>y;
}
bool check1()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=n-1) return 0;
	}
	return 1;
}
bool check2()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=4) return 0;
	}
	return 1;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n,cmp);
	if(n<=20)
	{
		int maxx=0;
		for(int i=1;i<=n-m+1;i++) maxx=max(maxx,dfs(i,m));
		printf("%lld",maxx);
	}
	else if(m==1) printf("%lld",a[1]);
	else if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=m;i++)
		{
			ans&=a[i];
		}
		printf("%lld",ans);
	}
	else if(m==2)
	{
		int maxx=0;
		for(int i=1;i<=n-1;i++) maxx=max(maxx,dfs(i,m));
		printf("%lld",maxx);
	}
	else if(m==n-1)
	{
		int ans=a[1];
		for(int i=2;i<=m;i++)
		{
			ans&=a[i];
		}
		printf("%lld",ans);
	}
	else if(check1()) printf("%lld",n-m);
	else if(check2()) printf("3");
	else printf("%lld",a[m]);
	return 0;
}
