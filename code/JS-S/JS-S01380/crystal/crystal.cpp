#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500001];
long long sum[500001];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	long long ans=1;
	for(long long i=1;i<=n;i++)
	{
		int l=1,r=i;
		int res=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)<=m+(sum[i]-sum[mid-1]))
			{
				r=mid-1;
				res=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	printf("%lld",ans);
	return 0;
}
