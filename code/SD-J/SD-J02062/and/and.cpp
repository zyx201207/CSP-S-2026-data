#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long p[55],n,s[N],m,ans,cnt,dp[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			dp[j]=max(dp[j],dp[j-1] and s[i]);
		} 
	}
	cout<<dp[m];
	return 0;
} 
