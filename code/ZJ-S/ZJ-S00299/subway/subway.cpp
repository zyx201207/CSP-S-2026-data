#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500050],a[20020],t[20020],dp[10020][10020];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<k;j++){
			for(int l=j+1;l<=k;l++){
				dp[a[j]][a[l]]=dp[a[l]][a[j]]=t[j]+t[l];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j) dp[i][j]=0;
			else if(dp[i][j]==0) dp[i][j]=1e9;
		}
	}
	for(int l=1;l<=m;l++){
		for(int i=1;i<m;i++){
			for(int j=i+1;j<=m;j++){
				dp[i][j]=dp[j][i]=min(dp[i][j],dp[i][l]+dp[j][l]);
			}
		}
	}
	while(q--){ 
		int l,r;
		cin>>l>>r;
		cout<<dp[l][r]+w[l]+w[r]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}