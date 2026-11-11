#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
ll a[N];
int n,m;
ll dp[N][N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ll mx=0;
	for(int i=1;i<=n;i++)cin>>a[i],mx=max(a[i],mx);
	if(n<=5000&&m<=5000){
		for(int i=1;i<=n;i++){
			dp[i][1]=max(a[i],dp[i-1][1]);
			for(int j=2;j<=m;j++){
				dp[i][j]=max(dp[i-1][j-1]&a[i],dp[i-1][j]);
			}
		}
		cout<<dp[n][m]<<"\n";
	}else{
		cout<<mx;
	}
	return 0;
}