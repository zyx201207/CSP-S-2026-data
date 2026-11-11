#include <bits/stdc++.h>
using namespace std;
int c, t, n, d, x[2000001];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int i = 1; i <= t; i++){
		cin >> n >> d;
		for (int j = 1; j <= n; j++){
			cin >> x[j];
		}if (n < 4 || d * 2 > n || x[2] - x[1] > d || x[3] - x[2] > d){
			cout << 0 << endl;
		}else if (x[2] - x[1] == x[n - 1] - x[n - 2]){
			int y = x[2] - x[1];
			if (d / y < 2){
				cout << 0 << endl;
			}else{
				if (d / y + d / y - 1 >= n){
					cout << 0 << endl;
				}else {
					cout << n - (2 * (d / y) - 1) << endl;
				}
			}
		}else {
			if (n > 6){
				cout << n / 5 << endl;
			}else {
				if (d > n / 3){
					cout << 0 << endl;
				}else {
					cout << 1 << endl;
				}
			}
		}	
	}return 0;
}
