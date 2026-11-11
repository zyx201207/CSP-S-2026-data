#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
inline ll read()
{
	ll f=1,x=0;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f*x;
}
int n,i,ans;
ll m,a[500005],sum[500005];
//RP++
//let me get S1= pls,CCF
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(i=1;i<=n;i++)
	{//考虑以i为标准的答案 
		//使用二分
		ll l=1,r=i,mid,ans_=1;
		while(l<=r)
		{
			mid=l+r>>1;
			if(a[i]*mid<=sum[i]-sum[i-mid]+m)ans_=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,ans_);
	}
	printf("%lld",ans);
	return 0;
}
/*
//freopen
//freopen
我要上人类迷惑行为大赏
酸酸甜甜! 
*/
