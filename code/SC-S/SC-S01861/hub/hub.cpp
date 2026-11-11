#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int ti=1;ti<=t;ti++){
		int n,k;
		cin>>n>>k;
		vector<int> v[n+1]
		for(int i=1;i<=n;i++){
			int s,e;
			cin>>s>>e;
			v[s].push_back(e);
			v[e].push_back(s);
		}
	}
	int dp[n+1][k+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			if(j>1){
				dp[i][j]=max(dp[i-1][j]+dp[i][j-1],dp[i-1][j-1]+v[i][j]);
			}
		}
	}
	cout<<dp[n][k]<<endl;
	return 0;
} 