#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long a[500005],m,sm;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	ans=0;
	sm=0;
	a[0]=0;
	for(int l=1,r=1;r<=n;r++)
	{
		sm+=(r-l)*(a[r]-a[r-1]);
		while(sm>m)
		{
			sm-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);
	return 0;
}
