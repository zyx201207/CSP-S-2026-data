#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],s[500005],f[500005],m;
ll cc(int i)
{
	ll x=f[i-1];
	while(a[i]*(i-x)-s[i-1]+s[x-1]>m)
		++x;
	return x;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,i,j;
	ll ans=1;
	scanf("%d %lld",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	f[1]=1;
	for(i=2;i<=n;++i)
	{
		f[i]=cc(i);
		ans=max(ans,i-f[i]+1);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
