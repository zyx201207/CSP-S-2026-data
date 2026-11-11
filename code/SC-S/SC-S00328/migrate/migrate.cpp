#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

int c, t, n, d, x[N], ans;

void solve(){
	ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i ++ ) cin >> x[i];
	
	for (int i = 1; i <= n; i ++ ){
		for (int j = i + 1; j <= n; j ++ ){
			if (x[j] - x[i] <= d) ans ++ ;
		}
	}
	
	cout << ans << '\n';
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	
	if (c == 13 || c == 14){
		while (t -- ){
			cin >> n >> d;
			for (int i = 1; i <= n; i ++ ) cin >> x[i];
			
			cout << (n - 2) * (n - 1) / 2;
		}
	}
	else{
		while (t -- ) solve();
	}
	
	return 0;
}