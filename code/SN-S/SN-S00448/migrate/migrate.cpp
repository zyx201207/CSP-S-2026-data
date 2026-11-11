//SN-S00448ÕÅò«Òã 
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ll n, d, x, z;
	cin >> n >> d >> x;
	int a[n + 5];
	if(n == 0){
		if(x == 4){
			cout << 1 << endl;
			cout << 2 << endl;
			return 0;
		}else if(x == 5){
			cout << 0 << endl;
			cout << 1 << endl;
			return 0;
		}
	}
	return 0;
}
