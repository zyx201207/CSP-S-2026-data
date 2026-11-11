#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+10;
int n,m,ans;
ll a[maxn],sum[maxn];
int read()
{
	int ret=0,w=1;char ch=0;
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {ret=(ret<<3)+(ret<<1)+(ch^48);ch=getchar();}
	return ret*w;
}
ll lread()
{
	ll ret=0,w=1;char ch=0;
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {ret=(ret<<3)+(ret<<1)+(ch^48);ch=getchar();}
	return ret*w;
}
void input()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=lread();
}
void deal()
{
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,mid=0;
		while(l<=r)
		{
			mid=l+(r-l)/2;
			if(m>=((i-mid)*a[i]-sum[i-1]+sum[mid-1])) r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
}
void solve()
{
	input();
	deal();
	printf("%d",ans);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int t=1;
	while(t--) solve();
	return 0;
}