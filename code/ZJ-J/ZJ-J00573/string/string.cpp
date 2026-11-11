#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n;
int a[N];
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld %c",a+i,c+i);
	int ans=0;
	for(int l=1,r=n;l<r;)
	{
		int tmp=min(a[l],a[r]);
		a[l]-=tmp;
		a[r]-=tmp;
		if(c[l]!=c[r])ans+=tmp;
		if(a[l]==0)++l;
		if(a[r]==0)--r;
	}
	printf("%lld",ans);
	return 0;
}
