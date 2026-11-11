#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],cha;
ll ans=1,l=1;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int r=2;r<=n;r++)
	{
		cha+=(a[r]-a[r-1])*(r-l);
		while(cha>m&&r>=l)
		{
			cha-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
