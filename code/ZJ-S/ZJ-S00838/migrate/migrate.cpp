#include<bits/stdc++.h>
using namespace std;
const int N = 5e3+5;
long long x[N];
long long dp[N][N];
long long num[N][N];
long long n, d;
void solved(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dp[i][j] = 0;
			num[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++){
		cin >> x[i];
	}
	for(int i = 1; i <= n; i++){
		int num = 1;
		int j = i+1;
		int nowi = i;
		while(j <= n){
			if(x[j]-x[nowi] > d){
				nowi = j-1;
				num++;
			}
			if(x[j]-x[j-1] > d){
				break;
			}
			dp[i][j] = num;
			j++;
		}
	}
	for(int i = 1; i <= n; i++){
		num[i][i] = 1;
	}
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			for(int k = i; k <= j; k++){
				if(dp[k][j] == 1 && dp[i][k]+dp[k][j] == dp[i][j]){
					num[i][j] += num[i][k];
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if(num[i][j] == 2)ans++;
		}
	}
	cout << ans << "\n";
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		solved();
	}
	return 0;
}
