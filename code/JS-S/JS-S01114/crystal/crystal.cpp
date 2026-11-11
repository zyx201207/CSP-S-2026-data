#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],s[500010];
int main()
{
	//freopen("crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	int ret=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,best=i;
		while(l<=r)
		{
			int mid=(l+r)/2;
			long long e=a[i]*1ll*(i-mid+1ll)-1ll*(s[i]-s[mid-1]);
			if(e<=m)
			{
				best=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		ret=max(ret,i-best+1);
	}
	cout<<ret;
	return 0;
}
