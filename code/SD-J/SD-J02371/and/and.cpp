#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+5;
ll n,m,a[N],dp[2005][2005];
bool cmp(ll x,ll y){
	return x>y; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		dp[i][1]=a[i];
	}
	if(n==m){
		ll sum=a[1];
		for(int i=2; i<=n; i++){
			sum&=a[i];
		}
		cout<<sum<<endl;
		return 0;
	}
	if(n>2000){
		sort(a+1,a+1+n,cmp);
		cout<<a[m]<<endl;
		return 0;
	}
	for(ll i=1; i<=n; i++){
		for(int j=2; j<=min(i,m); j++){
			for(int z=i-1; z>=j-1; z--){
				dp[i][j]=max(dp[z][j-1]&a[i],dp[i][j]);
				ll p=dp[z][j-1]&a[i];
//				cout<<i<<" "<<j<<" "<<p<<" "<<dp[i][j]<<endl;
			}
//			cout<<endl;
		}
	}
	ll maxx=0;
	for(int i=m; i<=n; i++){
		maxx=max(maxx,dp[i][m]);
	}
	cout<<maxx<<endl;
	return 0;
}
