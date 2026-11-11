#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=200001;
LL n,m,a[N],dp[1000][N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	LL ans = 0;
	dp[0][0]=a[0];
	for(int i=1;i<=m;i++){
		for(int j=n;j>=0;j--){
			dp[i][j]=max(dp[i-1][j]&a[j],dp[i][j-1]);
			ans=max(dp[i][j],ans);
		}
	}
	cout<<ans;
	return 0;
}
