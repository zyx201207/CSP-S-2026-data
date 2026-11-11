#include<bits/stdc++.h>
using namespace std;
int n,cnt=1,ans;
long long m,a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		while(m<(a[i]-a[i-1])*cnt)m+=a[i-1]-a[i-cnt+1],cnt--;
		m-=(a[i]-a[i-1])*cnt,cnt++,ans=max(cnt,ans);
	}
	printf("%d",ans);
    return 0;
}
