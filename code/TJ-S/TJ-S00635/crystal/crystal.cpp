#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
long long m,a[500010];
long long s[500010],s1[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++)
	{
		s[i]=a[i]-a[i-1];
		//printf("!%lld ",s1[i]);
	}
	int l=0,r=0;
	long long x=0;
	while(r<=n)
	{
		if(x>m)
		{
			ans=max(ans,r-l);
			x-=a[r]-a[l];
			l++;
		}
		else{
			x+=s[r]*(r-l);
			r++;
		}
	}
	if(x<m) ans=max(ans,r-l);
	else ans=max(ans,r-l-1);
	printf("%d",ans);
	return 0;
}
