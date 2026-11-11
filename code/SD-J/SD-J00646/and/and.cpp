#include<bits/stdc++.h>
using namespace std;
const int M=2*100000+1;
int n,m;
int dp[M];
int a[M];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=n;j>=1;j--){
		for(int i=m;i>=1;i--){
		if(i==1)dp[i]=max(a[j],dp[i]);
		else dp[i]=max(dp[i],dp[i-1]&a[j]);
		int f=dp[i-1]&a[j];
		//cout<<i<<" "<<j<<" "<<dp[i]<<" "<<f<<endl;
		
		}
	}
	cout<<dp[m];
	return 0;
} 
