#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define LL long long
int n,ans;
LL m,a[N],sum[N];
inline LL read()
{
	LL x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
		f=(c=='-')?-1:f,c=getchar();
	while(isdigit(c))
		x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;++i)
	{
		int l=1,r=i,res=-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			LL val=sum[i]-sum[mid-1];
			val=(1LL*i-mid+1)*a[i]-val;
			if(val<=m) res=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	printf("%d",ans);
	return 0;
} 
