#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+100;
int n,m;
int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<int> dp(m+1,-1),lo(m+1,-1);
	for(int i=1;i<=n;i++) cin>>a[i];
	lo[0]=0;
	dp[1]=a[1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j>i) continue;
			dp[j]=lo[j]; 
			dp[j]=max(dp[j],lo[j-1]&a[i]);
		}
		lo=dp;
	}
	cout<<dp[m];
	return 0;
}
