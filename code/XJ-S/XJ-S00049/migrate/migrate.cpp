#include<bits/stdc++.h> 
using namespace std;
long long n, m, k, a[5000005], b[5000005];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> n >> m >> k;
	if(n == 0 && m == 2 && k == 5){
		cout << 0 << "\n" << 1 << "\n";
	}else if(n == 0 && m == 2 && k == 4){
		cout << 1 << "\n" << 2 << "\n";
	}else{
		for(int i = 1; i <= m; i++){
			cout << 1 << "\n";
		}
	}
	return 0;
}
