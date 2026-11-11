#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
long long n,a[N],f[N],k,c,T,dp[N];
long long rf(long long x)
{
	long long l=1,r=n;
	while(l<r)
	{
		long long mid=(l+r)/2;
		if(a[mid]>x) r=mid;
		else if(a[mid]==x) return mid;
		else l=mid+1;
	}
	return r;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		long long ans=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			int op=a[i]+k;
			f[i]=rf(op);
			while(a[f[i]]>op) f[i]--;
		}
		for(int i=n-3;i>=1;i--)
		{
			long long fa=f[i];
			if(fa<2)
			{
				dp[i]=f[fa-1]-fa+dp[fa];
			}
			dp[i]=f[fa-1]-max(f[fa-2]+1,fa+1)+1+dp[fa];
		}
		for(int i=1;i<=n;i++)
		{
			ans+=dp[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}