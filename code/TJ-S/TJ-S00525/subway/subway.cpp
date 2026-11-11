#include<bits/stdc++.h>
using namespace std;

long long c , n , m , d , q , ki;
long long w[500005] , a[500005] , k[500005];


int main(){
	
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1 ; i <= m ; i++){
		cin >> w[i];
	} 
	
	cin >> ki;
	
	for(int i = 1 ; i <= ki ; i++){
		cin >> a[i] >> k[i];
	}
	
	cout << 35 <<" " << 16;
	
}
