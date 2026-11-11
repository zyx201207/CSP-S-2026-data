#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],n,m;
int dp[N][N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][0]=1; 
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
//			if(j<=i){
				dp[i][j]=max(dp[i-1][j]&a[i],dp[i][j]&a[i]);
//			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans=max(ans,1ll*dp[i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}

