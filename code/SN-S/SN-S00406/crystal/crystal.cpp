#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(ll len=n;len>=1;len--){
		for(ll l=1;l<=n-len+1;l++){
			ll r=l+len-1;
			if(sum[r]-sum[l-1]+m>=a[r]*len){
				cout<<len;
				return 0;
			}
		}
	}
	return 0;
}
