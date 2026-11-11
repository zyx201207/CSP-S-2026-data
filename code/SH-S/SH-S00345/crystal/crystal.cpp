#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int a[N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	#endif
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int cost=0,ans=1;
	for(int l=1,r=1;r<=n;r++)
	{
		cost+=(a[r]-a[r-1])*(r-l);
		while(cost>m)
		{
			cost-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}

