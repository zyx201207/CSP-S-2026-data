#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
typedef long long ll;
ll n,m,a[N],dp[N],maxn;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		dp[i]=a[i];
		for(ll j=m;j>=1;j--){
			dp[j]=dp[j-1]&a[i];
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
/*
4 2
3 15 12 12 
5 3
31 3 1 15 7
*/
