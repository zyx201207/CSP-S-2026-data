#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,ans;
long long m,a[N],s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)	scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1,p=0;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
		while((i-p)*a[i]-(s[i]-s[p])>m)	p++;
		ans=max(ans,i-p);
	}
	printf("%d",ans);
	return 0;
}

