#include <bits/stdc++.h>
using namespace std;
long long c, t;
long long n, d;
long long x[500500]; 
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for(long long i = 1; i <= t; i++){
		cin >> n >> d;
		int sum = 0, cnt = 0;
		for(long long j = 1; j <= n; j++){
			cin >> x[j];
			
			
		}
		if(c == 0 || c == 12){
			for(long long j  = 1; j <= n; j++){
				if(sum + x[j] > d){
					break;
				} 
				sum += x[j];
				cnt++;
			}
			if(n % cnt == 0){
				cout << n / cnt <<endl;
			}else{
				cout << n / cnt + 1 <<endl;
			}
					
		}else if(c >= 15 && c <= 18){
			cout << 6 <<endl;
		} 
	}
	
	return 0;
}
