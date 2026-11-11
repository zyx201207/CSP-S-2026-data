#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e12+7,N=2e3+7;
int ans=-INF,n,m,dp[N][N],a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[1][i]=a[i];
	}
	for(int j=2;j<=m;j++){
		for(int i=j;i<=n;i++){
			for(int k=1;k<i;k++){
				dp[j][i]=max(dp[j][i],dp[j-1][k]&a[i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[m][i]);
	}
	cout<<ans;
}
