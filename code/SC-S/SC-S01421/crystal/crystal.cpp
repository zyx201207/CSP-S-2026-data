#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans=1,l,x,dj;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	l=1;
	for(long long i=2;i<=n;++i)
	{
		x=a[i]-a[i-1];
		dj+=x*(i-l);
		while(dj>m)
		{
			dj-=a[i]-a[l];
			++l;
		}
		ans=max(ans,i-l+1LL);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}