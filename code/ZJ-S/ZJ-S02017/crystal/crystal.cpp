#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],l,ans,cnt,sum=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	l=1;
	sort(a+1,a+1+n);
	for(int i=2;i<=n;++i)
	{
		cnt+=sum*(a[i]-a[i-1]);
		++sum;
		while(cnt>m)
		{
			cnt-=a[i]-a[l];
			--sum;
			++l;
		}
		ans=max(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
