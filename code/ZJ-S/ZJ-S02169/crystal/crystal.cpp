#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+15;
int n,m;
int a[N];
int sum[N];
int suf[N];
int ans=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=n;i>=1;i--)
	{
		suf[i]=suf[i+1]+a[i];
	}
	for(int i=n;i>=1;i--)
	{
		if((i-1)*a[i]-sum[i-1]<=m)
		{
			ans=max(ans,i);
		}
		else
		{
			int lo=0;
			int hi=i-1;
			int res=-1;
			while(lo<=hi)
			{
				int mid=(lo+hi)>>1;
				int x=i-mid;// er fen wei zhi
				if(x*a[i]-(suf[mid]-suf[i])<=m)
				{
					res=mid;
					hi=mid-1;
				}
				else lo=mid+1;
			}
			ans=max(ans,i-res+1);
		}
	}
	cout<<ans<<endl;
	// 14:40 finish coding
	// 15:13 finish debugging
	// It is so many keng,not a very easy problem.
}
