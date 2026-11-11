#include <bits/stdc++.h>
using namespace std;
int n,l,r,ans;
long long m,a[500005],now;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	while(r<n)
	{
		now+=(r-l)*(a[++r]-a[r-1]);
		while(now>m)now-=a[r]-a[++l];
		ans=max(ans,r-l);
	}
	printf("%d",ans);
	return 0;
}