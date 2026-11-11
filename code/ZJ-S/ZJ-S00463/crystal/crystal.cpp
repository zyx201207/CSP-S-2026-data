#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n;
long long m;
long long a[N];
long long b[N],sum;
long long c[N];
bool flag;
int ans,l,r;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		b[i]=a[i+1]-a[i];
		if(b[i]<=m)flag=1;
	}
	for(int i=1;i<n;i++)
	{
		c[i]=c[i-1]+b[i];
	}
	if(!flag)
	{
		printf("0");
	}
	l=1,r=0;
	while(flag&&l<n&&r<n-1)
	{
		r++;
		sum+=b[r]*(r-l+1);
		while(l<n-1&&l<=r&&sum>m)sum-=(c[r]-c[l-1]),l++;
		ans=max(ans,r-l+2);
	}
	if(flag)printf("%d",ans);
	return 0;
}
