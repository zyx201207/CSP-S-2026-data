#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long d[500005];
long long c[500005];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
	c[1]=0;
	for(long long i=2;i<=n;i++) c[i]=c[i-1]+(i-1)*d[i];
	long long ans=0;
	for(long long i=1;i<=n;i++)
	{
		long long l=i,r=n;
		while(l<=r)
		{
			long long mid=(l+r)/2;
			long long x=c[mid]-c[i]-((i-1)*(a[mid]-a[i]));
			if(x<=m)
			{
				l=mid+1;
				long long sum=mid-i+1;
				ans=max(ans,sum);
			}
			else r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
