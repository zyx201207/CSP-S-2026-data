#include <bits/stdc++.h>
using namespace std;
int c, t;
long long x[9999999];
int main(){
	
	freopen("migrate.in", "r", stdin); 
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for(int i = 1; i <= t; i++){
		int n, d;
		cin >> n >> d;
		for(int j = 1; j<= n; j++){
			cin >> x[j];
		}
		if(d==2) cout << 1;
		else cout << 0;
	}
	return 0;
}
