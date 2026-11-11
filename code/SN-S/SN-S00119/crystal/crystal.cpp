#include<bits/stdc++.h>
using namespace std;
long long a[500005],m;
int n,ans;
int P(int x)
{
	int cur=0;
	long long sum=m;
	for(int i=x;i>=1;i--)
	    if(sum>=(a[x]-a[i])) cur++,sum-=(a[x]-a[i]);
	    else return cur;
	return cur;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool flag=1;
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=2;i<n;i++)
        if(a[i+1]-a[i]!=a[i]-a[i-1]) 
        {
        	flag=0;
        	break;
		}
	if(flag&&n!=1)
	{
		long long t=a[2]-a[1],sum=0,ans=0;
		for(int i=1;i<=n;i++) 
		    if(sum+t*ans<=m) sum+=t*ans,ans++;
		    else break;
		printf("%lld",ans);
		return 0;
	}
    for(int i=1;i<=n;i++) ans=max(ans,P(i));
	printf("%d",ans);
	return 0;
}
