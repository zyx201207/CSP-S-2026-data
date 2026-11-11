#include<bits/stdc++.h>
using namespace std;
int n,m;
long long dp[2001][2001];
long long a[200001];
long long mx=0;
long long andd;
void dfs(int op,int x,long long ad){
	if(x==m){
		mx=max(mx,ad);
		return;
	}
	for(int i=op+1;i<=n;i++)dfs(i,x+1,ad&a[i]);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
		if(i==1)andd=a[1];
		else andd&=a[i];
	} 
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==2){
		mx=0;
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				mx=max(mx,a[j]&a[i]);
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		cout<<andd;
		return 0;
	}
	if(n<=20){
		mx=0;
		for(int i=1;i<=n;i++)dfs(i,1,a[i]);
		cout<<mx;
		return 0;
	}
	for(int i=1;i<=n;i++)dp[i][1]=max(a[i],dp[i-1][1]);//选一个的最大值 
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){//从选两个开始 
			for(int k=1;k<i;k++){//从k转移 
				dp[i][j]=max(dp[k][j],dp[i][j]);//不选 
				dp[i][j]=max(dp[i][j],dp[k][j-1]&a[i]);//选 
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	} 
	cout<<dp[n][m];
	return 0;
}
