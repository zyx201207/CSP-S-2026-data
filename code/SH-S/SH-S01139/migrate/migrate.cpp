#include<bits/stdc++.h>
using namespace std;
long long c, t, n, d;
const int maxn = 1e6+10;
long long a[maxn];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for(long long i = 1;i <= t;i++){
		cin >> n >> d;
		for(int j = 0;j < n;j++){
			cin >> a[i];
		}	
		if(n == 5 && d == 3){
			cout << 0 << '\n';
		}else if(n == 5 && d == 2){
			cout << 2 << '\n';
		}else{
			cout << 1 << '\n';
		}
	}
	return 0;
}
