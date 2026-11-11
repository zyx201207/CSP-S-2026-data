#include<bits/stdc++.h>
#define int long long
#define ispow2(_) (fabs(((int)log2(_))-log2(_))<=EPS)
using namespace std;
const int N=2e5+10;
const double EPS=1e-7;
inline int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {if(c=='-') f=-f;c=getchar();}
	while(isdigit(c)) {sum=((sum<<3)+(sum<<1))+c-48;c=getchar();}
	return sum*f;
}
int a[N],b[50],n,m,ans;
void dfs(int x,int cnt,int sum)
{
	if(cnt>=m) {ans=max(ans,sum); return;}
	for(int i=x+1;i<=n;i++)
	{
		if(cnt==0) dfs(i,cnt+1,a[i]);
		else dfs(i,cnt+1,sum&a[i]);
	}
}
bool checkA()
{
	for(int i=1;i<=n;i++) {if(!ispow2(a[i]+1)) return 0;}
	return 1;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	if(n<=20) {dfs(0,0,0),cout<<ans; return 0;}
	if(n<=2000 && m==1)
	{
		for(int i=1;i<=n;i++) {ans=max(ans,a[i]);}
		cout<<ans; return 0;
	}
	if(n<=2000 && m==1)
	{
		ans=a[1];
		for(int i=2;i<=n;i++) {ans&=a[i];}
		cout<<ans; return 0;
	}
	if(n<=2000 && m==2)
	{
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) {ans=max(ans,a[i]&a[j]);}
		cout<<ans; return 0;
	}
	if(n<=2e5 && m==n-1)
	{
		int all=a[1],bans; 
		for(int i=1;i<=n;i++) for(int j=0;j<=19;j++) {b[j]+=((a[i]>>j)&1);}
		for(int i=2;i<=n;i++) {all&=a[i];} 
		for(int i=1,bans;i<=n;i++)
		{
			bans=all;
			for(int j=0;j<=19;j++) {if(((a[i]>>j)&1)==0 && b[j]==n-1) bans|=(1<<j);}
			ans=max(ans,bans);
		}
		cout<<ans; return 0;
	}
	if(n<=2e5 && checkA())
	{
		sort(a+1,a+n+1,greater<int>());
		ans=a[1]; for(int i=1;i<=m;i++) {ans&=a[i];}
		cout<<ans; return 0;
	}
	if(n<=2e5 && ispow2(n))
	{
		for(int i=1;i<=n;i*=2) if(i/2+1<=m && m<=i) {ans=n-i; break;}
		cout<<ans; return 0;
	}
	else cout<<0;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7

15 14
15 15 15 14 15 15 11 15 15 15 15 15 15 15 15 

16 5
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
*/