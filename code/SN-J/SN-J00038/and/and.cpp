#include<bits/stdc++.h>
using namespace std;
#define int long long dp
const int N=20000005;
	int n,m,ans;
	int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];}
	sort(a+1,a+n+1);
	dp[1][2]=a[i];
	dp[1][2]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			if(dp[j][2]=m){
				if(a[1]&dp[j][2]){
					dp[i][1]=a[i]&dp[j][2];
					dp[i][2]=a[i]&dp[j][2]+1;
				}
			}
		}
		ans=max(ans,dp[i][1])
	}
	
	return 0;
}
