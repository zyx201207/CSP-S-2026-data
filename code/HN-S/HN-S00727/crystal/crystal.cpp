#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,m;
int a[maxn],sum[maxn];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=1;
	for(int i=2;i<=n;i++)
	{
		int l=0,r=i+1,mid,len;
		while(l+1<r)
		{
			mid=(l+r)/2,len=i-mid;
			if(len*a[i]-(sum[i-1]-sum[mid-1])<=m)r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
} 
