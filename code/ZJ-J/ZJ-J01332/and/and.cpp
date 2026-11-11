#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,m,a[N],ans,dp[N][2],pre[N][2];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<min((ll)i,m);j++){
			dp[j][0]=max(pre[j][0],pre[j][1]);
		}
		dp[1][1]=a[i];
		for(int j=2;j<=min((ll)i,m);j++) dp[j][1]=max(pre[j-1][0]&a[i],pre[j-1][1]&a[i]);
		for(int j=0;j<=m;j++){
			pre[j][0]=dp[j][0];
			pre[j][1]=dp[j][1];
		}
		ans=max({ans,dp[m][0],dp[m][1]});
	}
	cout<<ans;
	return 0;
}