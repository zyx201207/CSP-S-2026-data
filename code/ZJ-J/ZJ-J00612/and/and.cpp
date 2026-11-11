#include<bits/stdc++.h>
using namespace std;
long long m,n,dp[3][200009],o[200009],aa;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>o[i];
		aa=max(aa,o[i]);
    }
    if(m==1){
    	cout<<aa;
    	return 0;
	}
	aa=0;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				aa=max(aa,o[i] & o[j]);
			}
		}
		cout<<aa;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=i;j++){
			dp[1][j]=max(o[i],max(o[i] & dp[0][j],o[i] & dp[1][j-1]));
		}
		for(long long j=1;j<=i;j++){
			dp[0][j]=dp[1][j];
		}
    }
    cout<<dp[0][m];
	return 0;
}
