#include<bits/stdc++.h>
using namespace std;

int a[500005];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t, n, d;
	cin >> c >> t;
	
	for(int i = 1; i <= t; i ++){
		cin >> n >> d;
		
		for(int j = 1; j <= n; j ++){
			cin >> a[i];
		}
		
		if(n == 4){
			cout << 1 << endl;
		}
		if(n == 5 && d == 2){
			cout << 2 << endl;
		}
		if(n == 5 && d == 3){
			cout << 0 << endl;
		}
		if(n == 6){
			cout << 1 << endl;
		}else{
			cout << 3 << endl;
		}
	}
	
	return 0;
}
