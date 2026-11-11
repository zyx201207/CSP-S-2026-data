#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],pre[500005];
bool check(int x)
{
	for (int i=x;i<=n;i++)
	{
		long long tmp=1ll*a[i]*x-(pre[i]-pre[i-x]);
		if (tmp<=m)
			return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	int l=1,r=n;
	while (l<r)
	{
		int mid=(l+r+1)>>1;
		if (check(mid))
			l=mid;
		else
			r=mid-1;
	}
	printf("%d",l);
	return 0;
} 