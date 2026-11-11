#include<bits/stdc++.h>
using namespace std;
long long arr[500005],sum[500005],m;
int n;
bool check(long long x)
{
	int i;
	for(i=x;i<=n;++i)
		if(x*arr[i]-sum[i]+sum[i-x]<=m)
			return true;
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long lt,rt,mid;
	int i;
	scanf("%d %lld",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%lld",&arr[i]);
	sort(arr+1,arr+n+1);
	for(i=1;i<=n;++i)
		sum[i]=sum[i-1]+arr[i];
	lt=1,rt=n;
	while(lt<=rt)
	{
		mid=(lt+rt)>>1;
		if(check(mid))
			lt=mid+1;
		else
			rt=mid-1;
	}
	printf("%d",rt);
	fclose(stdin);
	fclose(stdout);
}
