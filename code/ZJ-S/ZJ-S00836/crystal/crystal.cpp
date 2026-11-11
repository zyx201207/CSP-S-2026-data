#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N],ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,sum=0;
		while(l<=r)
		{
			int mid=l+r>>1;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)
				r=mid-1,sum=i-mid+1;
			else l=mid+1;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}