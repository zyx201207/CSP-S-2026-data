#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int dp[500000]={};
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>dp[i];
	}
	sort(dp,dp+n);
	for(int i=n-1;i>=0;i--){
		dp[i]=dp[i]-dp[0];
	}
	for(int i=n-1;i>=0;i--){
		int sumn=0,cnt=0;
		for(int j=0;j<=i;j++){
			sumn+=dp[i]-dp[j];
			cnt++;
			if(sumn==m&&i==j){
				cout<<cnt;
				return 0;
			}
		}
	}
} 
