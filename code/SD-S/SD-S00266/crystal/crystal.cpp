#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const lint M1=1e6+1000,M2=1e3+100;
lint n,m;
lint a[M1],s[M1];
lint sum,ans=1;
lint culc(lint l,lint r){return (r-l+1)*a[r]-(s[r]-s[l-1]);}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(lint i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(lint i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(lint i=1,j=1;j<=n;)
	{
		if(culc(i,j)>m) i++;
		else
		{
			ans=max(ans,j-i+1ll);
			j++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
