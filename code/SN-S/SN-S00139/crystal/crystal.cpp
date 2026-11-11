#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5,inf=1e18+1;
int n,m;
int a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=1,sum=0;
	int l=1;
	for(int r=2;r<=n;r++)
	{
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m&&l<=r) sum-=(a[r]-a[l++]);
//		cout<<l<<" "<<r<<" "<<sum<<endl;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
//15:09  AC T1
