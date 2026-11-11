#include <bits/stdc++.h>
using namespace std;

int n, d, x[1000] = {};

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t --){
		cin >> n >> d;
		for(int i = 1; i <= n; i ++){
			cin >> x[i];
		}
	}
	return 0;
} 
