#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c , t , n , d;
	long long x[1e9] , sum = 0;
	cin >> c >> t >> n >> d;
	while(t--){
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				int flag = 0 , l = x[i] + d;
				for (int k = l; k >= i; k--){
					
				}
			}
		}
	}
	return 0;
}

