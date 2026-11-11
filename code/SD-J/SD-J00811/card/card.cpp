#include<bits/stdc++.h>
using namespace std;
int n,m,a[555555],w[333333],dp[5555][3333],ans[555555];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	for(int i=n;i>=1;i--){
		if(w[a[i]]!=0){
			for(int j=1;j<=m;j++){
				dp[i][j]=dp[w[a[i]]][j];
			}
		}else{
			w[a[i]]=i;
			for(int j=1;j<=m;j++){
				dp[i][j]=dp[i+1][j];
			}
			dp[i][a[i]]++;
		}
		for(int j=1;j<=m;j++){
			ans[j]+=dp[i][j];
		}
	}
	for(int j=1;j<=m;j++){
		cout<<ans[j]<<" ";
	}
	return 0;
}
