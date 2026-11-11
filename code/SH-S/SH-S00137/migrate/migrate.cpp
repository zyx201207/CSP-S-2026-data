#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
int c, t, n;
long long a[N], d;
int main (){
	freopen("migrate.in", "r", stdin);
	freopen("migarte.out", "w", stdout);
	cin >> c >> t;
	while(t --){
		cin >> n >> d; int ans = 0;
		for(int i = 0; i < n; i ++){
			cin >> a[i];
		}
		for(int i = 0; i < n; i ++){
			if(i + 3 >= n){
				break;
			}
			if(a[i + 1] - a[i] <= d && a[i + 3] - a[i + 1] <= d && a[i + 2] - a[i] <= d && a[i + 3] - a[i + 2] <= d){
				ans ++;
			}
		}
		cout << ans << "\n";
	}
	return 0; 
}
// rp++ 
