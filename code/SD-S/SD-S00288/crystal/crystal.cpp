#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,ans;
ll m,a[N],s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<i&&a[i]*(i-j+1)-(s[i]-s[j-1])>m) j++;
		ans=max(ans,i-j+1);
	}
	printf("%d\n",ans);
	return 0;
}
