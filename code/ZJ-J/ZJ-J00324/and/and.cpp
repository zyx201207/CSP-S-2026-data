#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,cnt,cntt,x,a[200010];
int main()
{
	freopen("and.in","r",stdin);
//	freopen("and5.in","r",stdin);
	freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++)
	{
    	scanf("%lld",&x);
    	a[++cnt]=x;
	}
	for(long long k=29;k>=0;k--)
	{
		cntt=0;
		for(long long i=1;i<=cnt;i++) cntt+=((a[i]>>k)&1);
		if(cntt<m) continue;
		cntt=0;
		for(long long i=1;i<=cnt;i++)
		if((a[i]>>k)&1) a[++cntt]=a[i];
		ans=(ans^(1<<k));
		cnt=cntt;
	}
	printf("%lld\n",ans);
    return 0;
} 
