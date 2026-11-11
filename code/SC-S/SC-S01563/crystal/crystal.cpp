#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5 + 10 ;
long long data[MAXN] ;
void solve(){
	int n ; long long m ; cin >> n >> m ;
	for (int i = 1 ; i <= n ; i ++) {
		cin >> data[i] ;
	}
	sort(data + 1, data + 1 + n) ;
	long long maxx = -1 ;
	for (int i = 1 ; i <= n ; i ++) {
		long long cnt = 0 ;
		int sum = m ;
		for (int j = i - 1 ; j >= 1 ;j --){
			if (sum < (data[i] - data[j])) {
				break ;
			}
			sum -= data[i] - data[j] ;
			cnt ++ ;
		}
		if (cnt > maxx) maxx = cnt ;
	}
	cout << maxx + 1 ; 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin) ;
	freopen("crystal.out", "w", stdout) ;
	int t = 1 ;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}