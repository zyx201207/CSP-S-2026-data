#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
int main(){
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, t;
	cin >> c >> t;
	while(t--){
		long long n, d;
		cin >> n >> d;
		if(n == 1){
			cout << 0;
			return 0;
		}
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		long long p = a[2] - a[1];
		if(d <= p){
			cout << 0;
			return 0;
		}
		int smax = 1;
		cout << n << '\n';
	}
	return 0;
}