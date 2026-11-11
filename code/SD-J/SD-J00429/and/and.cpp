#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e3+10;
int a[N],dp[N][N],ma[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		ma[i]=max(ma[i-1],a[i]);
	}
	for (int i=1;i<=n;i++){
		dp[i][1]=ma[i];
		for (int j=2;j<=m;j++){
			dp[i][j]=max(dp[i-1][j-1]&a[i],dp[i-1][j]);
		}
	}
	cout<<dp[n][m];
	return 0;
}

