#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l,sum,ans,a[500010];
signed main()
{
	freopen("crystal.in","r",stdin);
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    l=1;sum=0;
    for(int i=1;i<=n;i++)
    {
    	sum+=(i-l)*(a[i]-a[i-1]);
    	while(sum>m&&l<i)
    	{
    		sum-=a[i]-a[l];
    		l++;
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld\n",ans);
	return 0;
 } 
