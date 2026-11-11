#include<bits/stdc++.h>
using namespace std;

int n;
long long d;
long long a[2000005];
long long dp[2000005];

void solve__11_12(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> a[i];
//	int last = 1;
//	dp[1] = 1;
//	long long ans = 0;
//	for(int i = 1; i <= n; i++){
//		if(a[i] - a[last] > d) last++;
//		for(int j = 1; j <= i - 1; j++) dp[i] += dp[j];
//	}
//	for(int i = 1; i <= n; i++){
//		if(dp[i] != 2) continue;
//		ans += (n - i + 1);
//	}
//	cout << ans << "\n";
//	if(a[2] - a[1] <= d && a[3] - a[2] <= d && a[4] - a[1] > d){
//		cout << n - 3 << "\n";
//	}
//	else{
//		cout << "0\n";
//	}
//	return;
	long long cha = a[2] - a[1];
	if(cha <= 0 || cha * 2 > d){
		cout << "0\n";	
		return;
	}
	long long ans = 0;
	long long p = d / cha;
	for(int i = 1; n - (i + p) + 1 > 0; i++){
		ans += p;
	}
	cout << ans << "\n";
}

void solve__13_14(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> a[i];
	long long idq = 0, idh = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] - a[1] <= d && a[n] - a[i] <= d){
			idq = i;
			break;
		}
	}
	for(int i = idq; i <= n; i++){
		if(a[i] - a[1] > d){
			idh = i - 1;
			break;
		}
	}
	long long ans = (idq - 1) * (n - idh);
	cout << ans << "\n";
} 

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int c, t;
	cin >> c >> t;
	///dp[0] = LLONG_MIN;
	if(c == 11 || c == 12){
		while(t--) solve__11_12();
	}
	else if(c == 13 || c == 14){
		while(t--) solve__13_14();
	}
	else{
		while(t--) solve__11_12();
	}
	
	return 0;
}
