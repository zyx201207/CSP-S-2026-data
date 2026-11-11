#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int n,k;
int a[N],sum[N],ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
		
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)//枚举最大值 
	{
		int l=1,r=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			int md=(i+mid)>>1;
			int tmp=(sum[i]+sum[mid-1])-(sum[md]+sum[md-1]);
			tmp+=(i+mid-md*2);
			if(tmp<=k)
				r=mid-1;
			else
				l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}

