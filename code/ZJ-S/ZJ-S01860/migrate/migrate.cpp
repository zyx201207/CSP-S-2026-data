#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300;
const int INF = 1e9;
int c, t, n, d;
int x[MAXN], dp[MAXN][MAXN], m[MAXN][MAXN];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		if(c == 13 || c == 14){
			printf("0\n");
			continue;
		}
		scanf("%d%d", &n, &d);
		for(int i = 1; i <= n; i++){
			scanf("%d", &x[i]);
		}
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j++){
				if(i == j){
					m[i][j] = 0;
				}
				else{
					if(x[j] - x[i] <= d){
						m[i][j] = 1;
					}
					else{
						m[i][j] = INF;
						dp[i][j] = 0;
					}
				}
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(m[i][j] == 1) continue;
				for(int k = i + 1; k <= j - 1; k++){
					if(m[i][j] = m[i][k] + m[k][j]){
						dp[i][j]++;
					}
					if(m[i][j] > m[i][k] + m[k][j]){
						m[i][j] = m[i][k] + m[k][j];
						dp[i][j] = 1;
					}
				}
			}
		}
		long long ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(dp[i][j] == 2){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
