#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m,a[500005],sum[500005];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=0;
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int ans=1;
    for(;r<=n;r++)
    {
        while(l<=r&&(a[r]*(r-l+1)-(sum[r]-sum[l-1]))>m) l++;
        ans=max(ans,r-l+1);
    }
    cout<<ans;
	return 0;
}
