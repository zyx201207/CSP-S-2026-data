#include<bits/stdc++.h>
using namespace std;
int n,m,a[2005],mx,cnt,dp[2005][2005],ans,nw,s,mxx;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		for (int j=1;j<=100;j++) if (pow(j,2)==a[i]) s=1;
	}
	if (!s){
		sort(a+1,a+n+1);
		cout << a[n-1] and a[n-2];
		return 0;
	}
	dp[0][0]=a[1];
	if (m==1){
		cout << 0;
		return 0;
	}
	else if (m==n){
		for (int i=1;i<=m;i++){
			ans&=a[i]&a[i-1];
		}
		cout << ans;
	}
	else{
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				dp[i][j]=dp[i-1][j];
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]&a[i]);
				cout << dp[i][j] << ' ';
			}
		}
		cout << dp[n][m];
	}
	return 0;
}
