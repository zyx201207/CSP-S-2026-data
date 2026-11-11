#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,a[500001],sum,max_;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	   scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(i=j=1;i<=n;i++)
	{
		sum+=(a[i]-a[i-1])*(i-j);
		for(;j<=i&&sum>m;j++)
		   sum-=a[i]-a[j];
		max_=max(max_,i-j+1);
	}
	cout<<max_;
	return 0;
}
