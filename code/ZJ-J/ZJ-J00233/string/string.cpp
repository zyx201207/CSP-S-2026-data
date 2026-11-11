//100
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],sum;
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int l=1,r=n;l<r;)
	{
		if(c[l]==c[r])
		{
			int d=min(a[l],a[r]);
			a[l]-=d;
			a[r]-=d;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}
		if(c[l]!=c[r])
		{
			int d=min(a[l],a[r]);
			sum+=d;
			a[l]-=d;
			a[r]-=d;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}
	}
	cout<<sum;
	return 0;
}