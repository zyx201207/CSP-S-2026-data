#include<bits/stdc++.h>
using namespace std;
const int N = 2010;
long long a[N],dp[N][N];
int n,m;
long long ans,max1;
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i],ans = ans & a[i],max1 = max(max1 , a[i]);
	if(m == n){
         cout<<ans;
         return 0;
	}
	if(m == 1){
         cout<<max1;
         return 0;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			dp[i][j] = max(dp[i-1][j],(j == 1 ? a[i]:dp[i-1][j-1]&a[i]));
		}
	}
	cout<<dp[n][m];
	return 0;
}
