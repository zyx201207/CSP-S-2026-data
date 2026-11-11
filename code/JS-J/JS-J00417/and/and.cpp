#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<int> dp(m+5);
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i<=m){
			dp[i]=0;
		}
	}
	dp[0]=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		for(int j=m;m>=1;m--){
				dp[j]=max(dp[j],(dp[j-1]&a[i]));
		}
		
	}
	cout<<dp[m];
	return 0;
}
