#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c,T;
long long n,d,a[N],s;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	for(int t = 1; t <= T; t++){
		cin >> n >>d;
		if(n < 4){
			cout << 0<< "\n";
			continue;
		} 
		for(int i = 1; i <= n ; i++){
			cin >> a[i];
		}
		if(n % d == 0){
			cout << n / d - 1 << "\n";
			continue;
		}
		else{
			cout << (n - 1) / d<< "\n";
			continue;
		}
	}
	return 0;
}

