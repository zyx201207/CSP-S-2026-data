#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];
bool check(int x)
{
	int sum=0;
	for(int i=1;i<=x;i++)
		sum+=(a[x]-a[i]);
	for(int i=1,j=x;j<=n;i++,j++)
	{
		if(sum<=m)return 1;
		sum+=(a[j+1]-a[j])*(x-1);
		sum-=a[j]-a[i];
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	int l=0,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			l=mid+1;
		else r=mid-1;
	}
	printf("%lld",l-1);
	return 0;
}
