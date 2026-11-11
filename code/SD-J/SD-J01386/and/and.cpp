#include<bits/stdc++.h>
using namespace std;
int a[200010];
long long dp[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,one=0,two=0,three=0,four=0;
	cin>>n>>m;
	memset(dp,-1,sizeof dp);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)one++;
		if(a[i]==2)two++;
		if(a[i]==3)three++;
		if(a[i]==4)four++;
	}sort(a+1,a+n+1);
	if(one+two+three+four==n){
		if(four>=m)cout<<4;
		else if(three>=m)cout<<3;
		else if(two+three>=m)cout<<2;
		else if(one+three>=m)cout<<1;
		else cout<<0;return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}cout<<dp[m];
	return 0; 
}

