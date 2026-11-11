#include<bits/stdc++.h>
using namespace std;
const int N = 11000;
int dp[N][N],y,a[N],n;
int main(){
//	cout<<1<<endl; 
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	cin>>n>>y;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1){
			dp[1][i] = max(dp[1][i-1],a[i]);
			//cout<<"i-1 = "<<dp[i-1][i-1]<<"  "<<a[i]<<endl;
			dp[i][i] = dp[i-1][i-1] & a[i];
		}
		else {
			dp[1][i] = a[i];
		}
//		cout<<i<<endl;
	}	
	//puts("flag");
	for(int i=2;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			//printf("try to excute %d : %d l1 : %d, l2 : %d\n",i,j,dp[i][j-1],dp[i-1][j]);
			dp[i][j] = max(dp[i][j-1],dp[i-1][j] & a[j]);
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			printf("%d ",dp[i][j]);
//		}
//		puts("");
//	}
	cout<<dp[y+1][n];

	
}
