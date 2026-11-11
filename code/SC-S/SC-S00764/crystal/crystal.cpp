#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,a[500010],dp[4000][10000];//前i个花了j时的最大答案 
bool f = 1;
ll dc;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(i == 2){
			dc = a[i]-a[i-1];
		}
		if(i >= 3 && a[i]-a[i-1] != dc){
			f = 0;
		}
	}
	if(f){
		ll as=0;
		for(int i = n;i >= 0;i--){
			m = m - (a[n]-a[i]);
			as++;
			if(m < 0 || i == 0){
				as--;
				cout<<as;
				return 0;
			}
		}
	}
//	cout<<
//	for(int i = 1;i <= n;i++){
//		for(int j = m;j >= 1;j--){
//			for(int x = j;x >= 0;x++){
//				dp[i][j] = max(dp[i][j],max(dp[i-1][]))
//			}
//			
//		}
//	}
	return 0;
} 
//2*1e7*8/1e3/1e3==>160