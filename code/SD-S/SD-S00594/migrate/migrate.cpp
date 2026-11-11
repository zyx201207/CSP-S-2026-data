#include <bits/stdc++.h>
using namespace std;
long long c , t , n , d, ans , e = 1;
long long x[1005] , cnt[1005], dp[1005][1005], b[1005];
int main(){
//	freopen("migrate.in" , "r" , stdin);
//	freopen("migrate.out", "w" , stdout);
cin >> c >> t;
	while(t--){
		ans = 0;
		cin >> n >> d;
		for(int i = 0; i < n; i++){
			cin >> x[i];
		}
		int num = 1;
		for(int i = 1; i < n; i++){
			if(x[i] - x[i - 1] <= d){
				num++;
			}
		}
		for(int i = 0; i < num; i++){
			for(int j = i + 1; j < num; j++){
				dp[i][j] = x[j] - x[i];
			}
		}

		for(int i = 0; i < num; i++){
			for(int j = i + 1; j < num; j++){
				if(dp[i][j] / d > 0 && dp[i][j] % d > 0 && (j - i + 1) / d == 2){
					ans++;
				}
			}
		}
		b[e++] = ans;
	}
	for(int i = 1; i <= e - 1;i++){
		cout << b[i] << endl;
	}
	return 0;
} 
