#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 5;
long long f[3005][3005];
long long cnt[3005][3005];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		memset(f, 0x3f3f3f3f, sizeof(f));
		memset(cnt, 0, sizeof(cnt));
		long long n, d;
		cin >> n >> d;
		vector<long long> x(n + 1);
		for(int i = 1; i <= n; i++) cin >> x[i];
		long long ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(abs(x[j] - x[i]) <= d){
					f[i][j] = 1;
					cnt[i][j] = 1;
				}
			}
		}
		for(int k = 2; k <= n - 1; k++){
			for(int i = 1; i < k; i++){
				for(int j = k + 1; j <= n; j++){
					if(f[i][k] + f[k][j] < f[i][j]){
						f[i][j] = f[i][k] + f[k][j];
						cnt[i][j] = 1;
					}else if(f[i][k] + f[k][j] == f[i][j]){
						cnt[i][j]++;
					}
				}
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(cnt[i][j] == 2) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
