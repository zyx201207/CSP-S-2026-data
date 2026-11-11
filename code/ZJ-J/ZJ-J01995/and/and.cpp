#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],dp[2][200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[0][i]=a[i];
	}
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++){
			ll sum1=0;
			for(int k=j+1;k<=n;k++){
				if(j==k)continue;
				sum1=max(sum1,dp[0][k]&a[j]);
			}
			dp[1][j]=sum1;
		}
		for(int k=1;k<=n;k++){
			dp[0][k]=dp[1][k];
		}
	}
	ll maxn=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,dp[0][i]);
	}
	cout<<maxn;
	return 0;
}
