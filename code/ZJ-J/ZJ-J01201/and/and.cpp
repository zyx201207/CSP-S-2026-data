#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5;
ll n,m,a[N],k,dp[N],ans,dig[N][31],sm[N],mx[N];
bool f;
bool check1()
{
	for(int i=1;i<=10;i++)
	{
		if(a[i]!=pow(2,i)-1) return false;
	}
	return true;
}
bool check2()
{
	
	for(int i=1;i<=10;i++)
	{
		if(a[i]!=i-1) return false;
	}
	return true; 
}
bool cmp(ll x,ll y)
{
	f=0;
	ll xx=x,yy=y;
	while(xx!=0 && yy!=0)
	{
		if(xx%2>yy%2) f=1;
		else f=0;
		xx=xx/2;
		yy=yy/2;
	}
	if(xx!=yy) return xx>yy;
	return f;
}
void dfs(ll len,ll cnt,ll s)
{
	if(n-len+1<m-cnt) return;
	if(cnt==m)
	{
		ans=max(ans,s);
			return;
	}
	if(len==n+1)  return;
	if(s==0) dfs(len+1,cnt+1,a[len]);
	else dfs(len+1,cnt+1,(a[len] & s));
	dfs(len+1,cnt,s);
}
void solve1()
{
	dfs(1,0,0);
	cout<<ans;
}
void solve2()
{
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,a[i]);
	}
	cout<<ans;
}
void solve3()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ans=max(ans,(a[i] & a[j]));
		}
	}
	cout<<ans;
}
void solve4()
{
	ans=a[1];
	for(int i=2;i<=n;i++) ans=(ans & a[i]);
	cout<<ans;
}
void solve5()
{
	ans=n;
	for(int i=n-1;i>=n-m+1;i--)
	{
		ans=(ans & a[i]);
	}
	cout<<ans;
}
void solve7()
{
	ll zuo[N],you[N];
	zuo[1]=a[1];
	you[n]=a[n];
	for(int i=2;i<=n;i++)
	{
		zuo[i]=(zuo[i-1] & a[i]);
	}
	for(int i=n-1;i>=1;i--)
	{
		you[i]=(you[i+1] & a[i]);
	}
	ans=max(zuo[n-1],you[2]);
	for(int i=2;i<=n-1;i++)
	{
		ans=max((zuo[i-1] & you[i+1]),ans);
	}
	cout<<ans;
}
void solve6()	
{
	ans=a[n];
	for(int i=n;i>=n-m+1;i--)
	{
		ans=(ans & a[i]);
	}
	cout<<ans;
}
void solve8()
{
	sort(a+1,a+1+n,cmp);ans=a[n];
	for(int i=n-1;i>=n-m;i--) 
	{
		ans = (ans&a[i]);
	}
	cout<<ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20) solve1();
	else if(m==1) solve2();
	else if(m==2 && n<=2000) solve3();
	else if(m==n) solve4();
	else if(m-1==n) solve7();
	else if(check1()) solve5();
	else if(check2()) solve6();	
	else solve8();
	return 0;
}
/*
 4 2
3 15 12 12
*/
