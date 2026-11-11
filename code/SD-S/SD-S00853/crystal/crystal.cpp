#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n;
ll m,a[N],sum[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1; i<=n; i++){
		sum[i]=sum[i-1]+a[i];
	}
	if (n<=5000){
		ll x=m;
		for (int i=1; i<=n; i++){
			ll cnt=1;
			x=m;
			for (int j=i-1; j>=1; j--){
				if (x>=abs(a[i]-a[j])){
					x-=abs(a[i]-a[j]);
				//	cout<<abs(a[i]-a[j])<<" "<<i<<" "<<j<<'\n';
					cnt++;
				}
			}
			ans=max(ans,cnt);
		//	cout<<'\n';
		}
		cout<<ans;
		return 0;
	}
	for (ll l=1,r=0; l<=n; l++){
		while(r+1<=n&&1LL*a[r+1]*(r-l+1)-(sum[r]-sum[l-1])<=m) r++;
		if (r<=n&&1LL*a[r]*(r-l)-(sum[r-1]-sum[l-1])<=m){
			ans=max(ans,r-l+1LL);
		}
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
