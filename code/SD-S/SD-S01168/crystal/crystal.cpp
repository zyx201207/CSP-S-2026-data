#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
using namespace std;
const int N=5e5+100;
ll rd()
{
	ll x=0,y=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')y=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return x*y;
}
int n,ans;
ll m,a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd();m=rd();
	rep(i,1,n)a[i]=rd();
	sort(a+1,a+1+n);
	ll sum=m;
	for(int i=2,j=1;i<=n;++i)
	{
		sum-=(a[i]-a[i-1])*(i-j);
		while(j<=i&&sum<0)sum+=(a[i]-a[j]),++j;
		ans=max(ans,i-j+1);
	}
	printf("%d",ans);
	return 0;
}

