#include<bits/stdc++.h>
using namespace std;
unsigned long long dp[2005][2005];
unsigned long long a[200005];
int n,m;
unsigned long long maxn=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		dp[i][1]=maxn;
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=2;k<=m;k++){
				dp[i][k]=max(dp[i][k],dp[j][k-1]&a[i]);
			}
		}
	}
	cout<<dp[n][m];	
	return 0;
}
