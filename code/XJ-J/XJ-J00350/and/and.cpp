#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e4+6383;
ll a[M],dp[M][M];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	ll maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i==1)dp[i][j]=max(a[j],dp[i][j-1]);
			else dp[i][j]=max(dp[i-1][j-1]&a[j],dp[i][j-1]);
		}
	}
	cout<<dp[m][n];
	return 0;
}
