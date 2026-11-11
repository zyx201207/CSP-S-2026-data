#include<bits/stdc++.h>
using namespace std;
int c, t, ans = 0;
int a[2000010];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		int n, d;
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++){
			for(int j = i + 3; j <= n; j++){
				if(abs(a[i] - a[j]) <= d){
					ans++;
				}
			}
		}
		for(int i = 1; i <= n; i++){
			a[i] = 0;
		}
	}
	cout << ans;
	return 0;
}