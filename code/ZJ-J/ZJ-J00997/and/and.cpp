#include<bits/stdc++.h>
using namespace std;
long long a[200007],dp[2007][2007],n,m;;
bool sA(int x){
	int s=0;
	while(s<=n){
		if(pow(2,s)-1==x) return 1;
		s++;
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	bool xxxA=1;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(!sA(a[i])) xxxA=0;
	}
	if(xxxA){
		cout<<pow(2,n-m+1)-1;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		dp[i][1]=a[i];
	}
	for(long long i=2;i<=n;i++){
		for(long long j=1;j<=min(m,i);j++){
			dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i-1][j-1]&a[i]));
		}
	}
//	for(long long i=1;i<=n;i++){
//		for(long long j=1;j<=min(m,i);j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	cout<<dp[n][m];
}
