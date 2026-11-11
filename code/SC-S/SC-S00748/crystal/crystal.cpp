#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],c[500010];
bool b(ll x,ll y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
		c[i]=a[i+1]-a[i];
	ll r=1,sum1=c[1],sum2=c[1],l=1;
	while(r<n)
	{
		if(sum1+c[r+1]*(l+1)<=m)
		{
			l++,r++;
			sum1+=c[r]*l;
			sum2+=c[r];
		}
		else
		{
			r++;
			sum1=sum1-sum2+c[r]*l;
			sum2=sum2-c[r-l]+c[r];
		}
	}
	printf("%lld",l+1);
	return 0;
}