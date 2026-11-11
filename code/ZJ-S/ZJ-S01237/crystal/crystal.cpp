#include<bits/stdc++.h>
#define endl '\n';
using namespace std;
#define int long long
int n,m,a[500005],sum[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1,l=1;i<=n;i++){
		while(l<i&&(i-l+1)*a[i]>sum[i]-sum[l-1]+m) l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
