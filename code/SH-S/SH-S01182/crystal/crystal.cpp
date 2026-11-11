#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,cost,ans,a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=1;
	while(r<=n){
		cost=(r-l+1)*a[r]-sum[r]+sum[l-1];
		if(cost<=m) ans=max(ans,r-l+1);
		if(cost>m) l++;
		else r++;
	}
	cout<<ans;
	return 0;
}
