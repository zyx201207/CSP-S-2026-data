#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
ll a[N];
ll dp[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin >> n >> m;
	ll cnt = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		cnt = max(cnt,a[i]);
	}
	for(int i = 1;i <= n;i++){
		for(int j = m;j >= 1;j--){
			dp[j] = max(dp[j],(j == 1 ? a[i] : dp[j-1]&a[i]));
		}
	}
	cout << dp[m];
	return 0;
}
