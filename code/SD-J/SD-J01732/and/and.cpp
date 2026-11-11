#include<bits/stdc++.h>
using namespace std;

int n,m,a[200010],dp[2000][2000];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=i;j<=n;j++){
			dp[i][j]=dp[i][j-1];
			if(i==1){
				dp[i][j]=max(dp[i][j],a[j]);
			}
			else{
				dp[i][j]=max(dp[i][j],int(a[j]&dp[i-1][j]));
			}
//			printf("i:%d j:%d dp:%d\n",i,j,dp[i][j]);
			if(i==m&&j==n){
				cout<<dp[i][j];
				return 0;
			}
		}
	}
	return 0;
}

