#include<bits/stdc++.h>
using namespace std;
int t[510000];
long long w[510000],a[510000],dp[510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=1e9;
		}
	}
	for(int i=1;i<=m;i++) dp[i][i]=0;
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,z;j<=k;j++){
			cin>>t[j]>>a[j];
			for(int l=1;l<j;l++){
				dp[t[l]][t[j]]=min(dp[t[l]][t[j]],a[j]+a[l]);
				dp[t[j]][t[l]]=min(dp[t[j]][t[l]],a[l]+a[j]);
			}
		} 
	}
	for(int k=1;k<=m;k++){
		for(int j=1;j<=m;j++){
			for(int i=1;i<=m;i++){
				//cout<<i<<" "<<j<<" "<<dp[i][j]<<" ";
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				//cout<<dp[i][j]<<"\n";
			}
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<w[l]+dp[l][r]+w[r]<<"\n";
	}
	return 0;
}
