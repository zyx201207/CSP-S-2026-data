#include<bits/stdc++.h>
using namespace std;
const long long maxn=5e5+5;
long long n,m,i,j,l,r,tmp,ans,h,mid;
long long a[maxn],sum[maxn];
bool check(long long st,long long la)
{
	long long len=la-st+1,cmw,f;
	cmw=sum[la]-sum[st-1],f=len*a[la];
	if(cmw+m>=f) return true;
	else return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i]; 
	for(i=1;i<=n;i++)
	{
		l=1,r=i,tmp=i;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(mid,i))
			{
				r=mid-1;
				tmp=mid;
			}
			else l=mid+1;
		}
		h=i-tmp+1;
		ans=max(ans,h);
	}
	printf("%lld",ans);
	return 0;
}
//luogu uid:562443
//My fifth CSP
//Not for anyone,just for me.
//;;
//freopen y1 genshin
//数据删除 查无此人
//Oct31==Dec25?
//16岁!
//Asz->XJ OIer->MOer
//for my love.
//