#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
ll n,m,a[N],sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		sum[i]=a[n]-a[i];
	}
	ll cnt=0;
	int ans=1;
	for(int i=n,j=n;i>=1;i--)
	{
		cnt+=sum[i]-sum[j];
		while(cnt>m)
		{
			cnt-=(j-i)*(sum[j-1]-sum[j]);
			j--;
		}
		ans=max(ans,j-i+1);
	}
	printf("%d",ans);
	return 0;
}
