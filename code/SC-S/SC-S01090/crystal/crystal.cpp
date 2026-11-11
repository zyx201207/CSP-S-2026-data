#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],cha[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++)
	{
		cha[i]=a[i]-a[i-1];
	}
	long long i=1,j=1,jia=0,ans=0;
	while(j<=n)
	{
		j++;
		jia+=(cha[j]*(j-i));
		while(jia>m)
		{
			jia-=(a[j]-a[i]);
			i++;
		}
		ans=max(ans,j-i+1);
	}
	printf("%lld",ans);
	return 0;
}