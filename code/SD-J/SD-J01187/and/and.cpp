#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll N = 2e5 + 10;
ll n, m;
ll a[N];

ll dp[N][400];

ll ans = -1900000; 

ll f(ll a, ll b){
	if(a == 0) return b;
	else return a&b;
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("and.in","r", stdin);
	freopen("and.out","w",stdout);

	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	if(m == 1) {
		sort(a+1,a+n+1);
		cout << a[n] << '\n';
		return 0;
	}
	if(n == m){
		ans = a[1];
		for(int i =2; i<= n; i++){
			ans = ans & a[i];
		}
		cout << ans <<'\n';
		return 0;
	}
	
	//dp³õÊ¼»¯ 
	for(int i = 1; i <= n; i++){
		dp[i][0] = a[i];
	}
	
	
	//----------------------------------
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			dp[i][j] = max(f(dp[i-1][j-1], a[i]) , dp[i-1][j]); 
		}
	}
	
	for(int i = 0; i<= n ; i++){
		ans = max(ans , dp[i][m]);
	}
	
	cout << ans << "\n";
	return 0;
}
