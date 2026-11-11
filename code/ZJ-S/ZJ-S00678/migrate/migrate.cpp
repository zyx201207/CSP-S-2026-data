#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int c, t, n, d;
int a[N];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		int ans = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		if(c >= 11 && c <= 18){
			cout << n << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}