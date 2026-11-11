#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m,mm;
ll a[500010];
int maxn=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		mm=m;
		int ans=1;
		for(int j=i-1;j>=1;j--)//a[j]~(become)a[i]
		{
			if(mm>=(a[i]-a[j]))
			{
				mm-=(a[i]-a[j]);
				ans++;
			}
			else break;
		}
		maxn=max(maxn,ans);
	}
	printf("%d",maxn);
	return 0;
}
