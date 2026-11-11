#include<bits/stdc++.h>
using namespace std;

int n, m, a[200005];
vector<int> dp(200005, INT_MAX);

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			dp[j] = max(a[i], dp[j]&a[i]);
			cout << dp[j] << " " << a[i] << " " << (dp[j]&a[i]) << endl;
		}
	}
	cout << dp[m];
	
	return 0;
}
