#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,r=1,ans=0;
	long long m,mx,sum=0;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int l=1;l<=n;l++)
	{
		for(r=max(l,r);r<n;r++)
		{
			if(sum+(a[r+1]-a[r])*(r-l)>m)
				break;
			sum+=(a[r+1]-a[r])*(r-l+1);
			ans=max(ans,r-l+2);
		}
		sum-=a[r]-a[l];
		if(r==n)
			break;
	}
	printf("%d\n",ans);
}