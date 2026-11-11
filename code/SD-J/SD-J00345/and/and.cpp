#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],dp[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=30;k++){
			if(pow(2,k)>=a[i]){
				dp[i]=pow(2,k)-1;
				break; 
			}
		}
	}
	sort(a+1,a+n+1,greater<int>());
	for(int j=1;j<=m;j++){
		dp[j]=max(dp[j],dp[j-1]&a[j]);
	}cout<<dp[m];
	return 0;
} 
