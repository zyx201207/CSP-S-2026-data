#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+50;
int n,m,ans;
int a[N],d[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
	d[n+1]=1e9;  int l=1,r=1;
	while(l<=r && r<=n){
		while(d[r+1]==0) r++;
		ans=max(ans,r-l+1);
		if ((r-l+1)*d[r+1]<=m){
			m-=(r-l+1)*d[r+1];
			r=upper_bound(a+1,a+n+1,a[r])-a;
		}
		else {
			m+=a[r]-a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
