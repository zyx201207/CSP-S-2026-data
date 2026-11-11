#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,l=1,sum=0,ans=1;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]); 
	sort(a+1,a+n+1);
	sum=a[1];
	for(int i=2;i<=n;i++)
	{
		while(m<a[i]*(i-l)-sum&&l<i)
			sum-=a[l++];
		sum+=a[i];
		ans=max(ans,i-l+1);
	}
	printf("%lld\n",ans);
	return 0;
}

