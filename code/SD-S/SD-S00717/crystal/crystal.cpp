#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],s[N],n,m;
bool check(int x)
{
	for(int i=1;i<=n-x+1;i++)
	{
		int sum=a[i+x-1]*x-(s[i+x-1]-s[i-1]);
		if(sum<=m) return true; 
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%lld",r);
	
	return 0;
}
