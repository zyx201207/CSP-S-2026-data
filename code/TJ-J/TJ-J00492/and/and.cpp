#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[200005],a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[0]=INT_MAX;
	for(int j=1;j<=n;j++){
		for(int i=m;i>=1;i--){
			dp[i]=max(dp[i-1]&a[j],dp[i]);
		}
	}
	cout<<dp[m];
} 
