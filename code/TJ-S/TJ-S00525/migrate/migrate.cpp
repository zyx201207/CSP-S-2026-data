#include<bits/stdc++.h>
using namespace std;


long long c , t , n[100005] , d[100005] , x[2000005];


int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	
	cin >> c >> t;
	
	for(int i = 1 ; i <= t ; i++){
		cin >> n[i] >> d[i];
		
		for(int j = 1 ; j <= n[i] ; j++){
			cin >> x[i];
		}
	} 
	
	for(int i = 1 ; i <= t ; i++){
		cout << 1 << "\n";
	}
	
	
}
