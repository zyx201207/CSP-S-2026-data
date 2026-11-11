#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m;
	vector<ll> a(n+1),s(n+1,0);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll ans=1;
	for(int i=1;i<=n;i++)
	{
		int L=1,R=i,p=i;
		while(L<R)
		{
			int mid=L+R>>1,len=i-mid+1;
			if(1ll*len*a[i]-(s[i]-s[mid-1])<=m) R=mid,p=mid;
			else L=mid+1;
		}
		ans=max(ans,(ll)i-p+1);
	}
	cout<<ans<<'\n';
	return 0;
}