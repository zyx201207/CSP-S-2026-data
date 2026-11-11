#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,ans;
long long m,a[500005],s[500005];
long long cost(int L0,int R0)
{
	return a[R0]*(R0-L0)-s[R0]+s[L0];
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i=0;i<n;i+=1) scanf("%lld",&a[i]);
	sort(a,a+n);
	for (int i=0;i<n;i+=1) s[i+1]=s[i]+a[i];
	for (int R=1;R<n;R+=1)
	{
		int l=0,r=R-1,mid,L=R;
		while (l<=r)
		{
			mid=(l+r)/2;
			if (cost(mid,R)<=m) r=mid-1,L=mid;
			else l=mid+1; 
		}
		ans=max(ans,R-L+1);
	}
	printf("%d",ans);
	return 0;
}
