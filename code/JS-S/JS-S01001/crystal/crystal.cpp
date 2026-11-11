#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
ll m;
ll a[500005],pre[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	ll ans=1;
	for(int i=2;i<=n;i++)
	{
		ll sum=0,j=i-ans+1;
		if(a[i]*ans-(pre[i]-pre[j-1])>m) continue;
		sum=a[i]*ans-(pre[i]-pre[j-1]);
		while(j>1 and sum<=m)
		{
			if(sum+a[i]-a[j-1]<=m) ans++,j--,sum+=a[i]-a[j];
			else break;
		}
	}
	cout<<ans;
	return 0;
}
