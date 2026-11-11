#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[2005][2005][2];
int a[200005];
bool isA=1;
int n,m;
int tibol(int x){
	return x&(x+1);
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(tibol(a[i])!=0){
			isA=0;
		}
	}
	if(isA==1){
		sort(a+1,a+n+1,cmp);
		int minn=INT_MAX;
		for(int i=1;i<=m;i++){
			minn=min(a[i],minn);
		}
		cout<<minn;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i<j)/*全选都选不够*/{
				dp[i][j][1]=dp[i][j-1][1];//继承这一轮全选的情况
			}
			else if(i==j)/*必须全选*/{
				if(j==1){
					dp[i][j][1]=a[i];//刚上来必须先选第一个
				}
				else{
					dp[i][j][1]=max(dp[i-1][j-1][0],dp[i-1][j-1][1])&a[i];//继承上一轮全选情况再选上这一轮
				}
			}
			else{
				if(j==1){
					dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]);//不选，继承上一轮最大值
					dp[i][j][1]=a[i];//选上这一轮
				}
				else{
					dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]);//不选，继承上一轮最大值
					dp[i][j][1]=max(dp[i][j-1][0]&a[i]/*这一轮没选时的最大值*/,max(dp[i-1][j-1][0],dp[i-1][j-1][1])&a[i]/*上一轮全选再选上这一轮*/);
				}
			}
		}
	}
	cout<<max(dp[n][m][0],dp[n][m][1]);
	return 0;
}
