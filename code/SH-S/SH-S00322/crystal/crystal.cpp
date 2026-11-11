#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[1000005],n,m;
int check(ll num,ll cnt)
{
	ll t=0;
	for(int i=1;i<=n;i++)
		if(arr[i]<=num)
			t+=num-arr[i];
	return t<=cnt?1:0;
}
ll bs(ll lt,ll rt)
{
	ll mid;
	while(lt<=rt)
	{
		mid=(lt+rt)>>1;
		if(check(arr[mid],m))
			lt=mid+1;
		else
			rt=mid-1;
	}
	return arr[rt];
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&arr[i]);
	sort(arr+1,arr+1+n);
	ll tmp=bs(1,n),ans=0;
	for(int i=1;i<=n;i++)
		if(arr[i]<=tmp)
			ans++;
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
