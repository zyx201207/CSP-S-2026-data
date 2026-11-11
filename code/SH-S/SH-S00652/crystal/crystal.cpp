#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,mx,mn;
long long m,ans;
int a[N];
int dp[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int k=m;k>=0;k--){
			long long cost=k-a[i];
			dp[k]=max(dp[k],dp[k-cost]+1);
		}
	}
	cout << dp[m];
	return 0;
} 
