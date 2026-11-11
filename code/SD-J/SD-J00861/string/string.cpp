#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+10;
int n;
int a[N];
char b[N];
int ans;

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld %c",&a[i],&b[i]);
	for(int l=1,r=n;l<=r;)
	{
		if(b[l]!=b[r])
		{
			ans+=min(a[l],a[r]);
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				a[r]=0;
			}
			if(a[r]>a[l])
			{
				a[r]-=a[l];
				a[l]=0;
			}
			if(a[r]==a[l])a[l]=a[r]=0;
			if(a[l]==0)l++;
			if(a[r]==0)r--;
		}
		else
		{
			
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				a[r]=0;
			}
			if(a[r]>a[l])
			{
				a[r]-=a[l];
				a[l]=0;
			}
			if(a[r]==a[l])a[l]=a[r]=0;
			if(a[l]==0)l++;
			if(a[r]==0)r--;
		}
	}
	printf("%lld",ans);
	return 0;
}
