#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1,last=m;
	int ans=0;
	for(r=2;r<=n;r++)
	{
		while(last<(r-l)*(a[r]-a[r-1])){
			last+=(a[r-1]-a[l]);l++;
		}
		last-=(r-l)*(a[r]-a[r-1]);
		ans=max(ans,(r-l+1));
	}
	cout<<ans;
	return 0;
}
