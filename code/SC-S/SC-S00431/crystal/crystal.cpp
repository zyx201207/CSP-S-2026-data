#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	int z=n/2+1;
	for(int i=z-1;i>=1;i--)
	{
		int s=a[z]-a[i];
		if(s==0)
		{
			ans++;
			break;
		}
		if(s<=m)
		{
			ans++;
			m=m-s;
		}	
	} 
	for(int i=z;i<=n;i++)
	{
		if(a[i]==a[z])
		{
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
} 