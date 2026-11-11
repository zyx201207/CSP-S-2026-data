#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],dp[20005][20005],maxz=0x80000000;
bool pd(int A,int B){
	return A>B;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n==m){
		int z=0;
		for(int i=1;i<=n;++i){
			z=z&a[i];
		}
		cout<<z;
		return 0;
	}
	sort(a+1,a+n+1,pd);
	for(int i=1;i<=n;++i){
		dp[i][1]=a[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=2;j<=m;++j){
			if(j>i)break;
			dp[i][j]=max(dp[i][j],dp[i-1][j-1]&a[i]);
			dp[i][j-1]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	for(int i=m;i<=n;++i){
		maxz=max(dp[i][m],maxz);
	}
	cout<<maxz;
	return 0;
}