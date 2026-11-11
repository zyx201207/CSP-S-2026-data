#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m,a[N];
int check(int x)
{
	int x1=x,num=0;
	while(x1) num+=(x1&1),x1>>=1;
	if(num!=m) return 0;
	long long ans=(1ll<<31)-1;
	for(int i=1;i<=n;i++)
		if(x&(1<<(i-1))) ans&=a[i];
	return (int)ans;
}
void solve1()
{
	int ans=0;
	for(int i=0;i<=((1<<n)-1);i++)
		ans=max(ans,check(i));
	printf("%d",ans);
}
void solve2()
{
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,a[i]);
	printf("%d",ans);
}
void solve3()
{
	int ans=a[1];
	for(int i=2;i<=n;i++) ans&=a[i];
	printf("%d",ans);
}
void solve4()
{
	int f[n+10]={0},g[n+10]={0},ans=0;
	f[1]=a[1],g[n]=a[n];
	for(int i=2;i<=n;i++) f[i]=f[i-1]&a[i];
	for(int i=n-1;i>=1;i--) g[i]=g[i+1]&a[i];
	for(int i=2;i<n;i++) ans=max(ans,f[i-1]&g[i+1]);
	ans=max(ans,f[n-1]),ans=max(ans,g[2]);
	printf("%d",ans);
}
void solve5()
{
	int ans=0;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			ans=max(ans,a[i]&a[j]);
	printf("%d",ans);
}
void solve6()
{
	int x=1,ans=n-1;
	while(m>x)
	{
		x+=ans&(-ans);
		ans-=ans&(-ans);
	}
	printf("%d",ans);
}
void solve7()
{
	sort(a+1,a+1+n);
	printf("%d",a[n-m+1]);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	bool b1=1;
	for(int i=1;i<=n;i++) if(a[i]!=i-1) b1=0;
	if(m==1) solve2();
	else if(n==m) solve3();
	else if(m==n-1) solve4();
	else if(m==2) solve5();
	else if(n<=20) solve1();
	else if(b1) solve6();
	else solve7();
	return 0;
}

