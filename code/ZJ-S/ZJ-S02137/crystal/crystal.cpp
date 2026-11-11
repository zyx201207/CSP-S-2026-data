#include<bits/stdc++.h>
using namespace std;
int n,l,ans;
long long a[500007],m,an;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	l=1;
	for(int i=2;i<=n;i++)
	{
		while(an+(a[i]-a[i-1])*(i-l)>m) an-=a[i-1]-a[l++];
		an+=(a[i]-a[i-1])*(i-l);
		ans=max(i-l+1,ans);
	}
	printf("%d\n",ans);
	return 0;
}