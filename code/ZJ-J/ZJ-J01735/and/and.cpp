#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a,b,n[200005] ={},cs = 1,bh = 0;
	int dp[200005] = {};
	cin >> a >> b;
	for(int i = 0;i < a;i++){
		cin >> n[i];
	}
	sort(n,n+a);
	if(b == 1){
		cout << n[a-1];
		return 0;
	} 
	reverse(n,n+a);
	dp[0] = n[0] & n[1];
	for(int i = 1;i < a;i++){
		dp[i] = max(dp[i-1] & n[i],dp[i-1]);
		cs += !(dp[i] == dp[i-1]);
		bh = (dp[i] == (dp[i-1] & n[i])) ? i : bh;
		if(cs == b){
			sort(dp,dp+a);
			cout << dp[a];
			return 0;
		}
	}
	sort(dp,dp+a);
	int k = dp[a-1];
	if(cs < b){
		for(int i = bh+1;cs < b-1;cs++,i++){
			k &= n[i];
		}
	}
	if(k == 0) cout << 1;
	else cout << k;
	return 0;
} 

