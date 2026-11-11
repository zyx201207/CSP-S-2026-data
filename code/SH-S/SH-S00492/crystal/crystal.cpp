#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int max_n=500005;
int n,m;
int a[max_n];
bool check(int len)
{
	if(len ==1)
		return true;
	int ans =0;
	for(int i=1;i<=1+len-1;i++)
		ans+=(a[1+len-1]-a[i]);
	if(ans<=m)
		return true;
	for(int i=len+1;i<=n;i++)
	{
		ans-=a[i-1]-a[i-1-len+1];
		ans += (len-1) * (a[i]-a[i-1]);
		if(ans<=m)
			return true;
	}
	return false;
}
signed main()
{

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);	
	sort(a+1,a+n+1);
	int ans =0;
	for(int i=25;i>=0;i--)
	{
		int t=ans + (1<<i);
		if(t<=n && check(t))
			ans =t;
	}
	printf("%lld",ans);
	return 0;
}
