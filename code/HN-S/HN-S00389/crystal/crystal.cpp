#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],cnt,b[500005];
int main()
{
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)b[i]=a[i]+b[i-1];
	for(int i=1;i<n;i++)
	{
		int l=i+1,r=n,mid;
		while(l+1<r)
		{
			mid=l+(r-l)/2;
			if(a[mid]*(mid-i+1)-b[mid]+b[i-1]<=m)l=mid;
			else r=mid;
		}
		if(l-i+1>cnt)cnt=l-i+1;
	}
	printf("%lld",cnt);
	return 0;
}
