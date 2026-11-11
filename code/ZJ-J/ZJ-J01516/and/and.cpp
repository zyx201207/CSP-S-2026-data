#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2010
int dp[N][N],a[N],n,m,ma,ans; 
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(NULL); 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],dp[i][1]=a[i],ma=max(a[i],ma);
	if(m==1){
		cout<<ma;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=2;k<=m;k++)
				dp[i][k]=max(dp[i][k],dp[j][k-1]&a[i]);
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i][m]);
	}
	cout<<ans;
}//5 3 31 3 1 15 7
