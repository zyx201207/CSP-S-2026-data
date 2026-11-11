#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=5e5+7;
int n;
ll m,a[N],sum[N];
#define LEN ((ll)r-l+1ll)
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	
	ll ans=0;	
	for(int l=1,r=1;l<=n;l++)
	{
		r=max(r,l);
		while(r<=n && a[r]*LEN-(sum[r]-sum[l-1])<=m)
		{
			ans=max(ans,(ll)LEN);
			r++;
		}
		if(a[r]*LEN-(sum[r]-sum[l-1])>m)
			r--;
	}
	
	cout<<ans;
	
	return 0;
}
