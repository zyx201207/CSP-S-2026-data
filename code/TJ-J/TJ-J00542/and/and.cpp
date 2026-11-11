#include<bits/stdc++.h>
using namespace std;
//int dp[200010][200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200010],ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>20){
		if(m==1){
			for(int i=1;i<=n;i++){
				ans=max(ans,a[i]);
			}
			cout<<ans;
			return 0;
		}
		if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j)ans=max(ans,a[i]&a[j]);
				}
			}
			cout<<ans;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i!=j&&i!=k&&j!=k)ans=max(ans,a[i]&a[j]&a[k]);
			}
		}
	}
//	for(int i=2;i<=m;i++){
//		for(int j=1;j<=n;j++){
//			dp[i][j]=max(dp[i-1][j]&a[j],dp[i][j-1]);
//		}
//	}
//	for(int i=i;i<=n;i++){
//		ans=max(ans,dp[3][i]);
//	}
	cout<<ans;
	return 0;
}//Trick||Treat!
