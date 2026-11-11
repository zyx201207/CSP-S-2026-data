//Oct31==Dec25? 关于今天是圣诞节这件事 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int check(){
	
}
int n,m,A=1;
int a[500005],diff[500005],dp[500005],ans=-1;
signed main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	diff[1]=0;
	for(int i=2;i<=n;i++)diff[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i]=max(dp[i-j]+1,dp[i])
		}
	}
	cout<<dp[n];
}
//注意到要求中是至多，所以，可以算是个——我也不知道 
