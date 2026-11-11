#include<bits/stdc++.h>
using namespace std;
int dp[5010][5010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,a[5010],ch[5010],minn=1e9;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(i!=n){
			ch[i]=a[i+1]-a[i];
			dp[2][i]=ch[i];
			minn=min(minn,ch[i]);
		}
	}
	if(m<minn){
		cout<<1;
		return 0;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=3;j<=n;j++){
//			if(dp[i][j-1]+dp[i+j-2][2]*(j-1)<=m){
//				dp[i][j]=dp[i][j-1]+dp[i+j-2][2]*(j-1);
//			}
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
for(int j=3;j<=n;j++){
	for(int i=1;i<=n;i++){
		if(dp[j-1][i]+dp[2][i+j-2]*(j-1)<=m&&i+j<=n){
			dp[j][i]=dp[j-1][i]+dp[2][i+j-2]*(j-1);
		}
	}
	
}
	int ans=0,y=0,x=0;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(ans<=dp[i][j]){
				ans=dp[i][j];
				x=i,y=j;
			}
		}
	}
	cout<<x-y+1;
	return 0;
}//Oct31==Dec25?
