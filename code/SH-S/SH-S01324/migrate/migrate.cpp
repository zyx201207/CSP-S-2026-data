#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6+5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int c, T;
ll n, dp[5005][5005], f[5005][5005];
//bool fl[5005][5005];
ll d;
ll x[N];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
		if(c <= 6){
			memset(dp, 0x3f, sizeof(dp));
			memset(f, 0, sizeof(f));
			for(int len = 1; len < n; len++){
				for(int i = 1; i <= n; i++){
					int j = i+len;
					if(d >= x[j]-x[i]){
						dp[i][j] = 1;
						continue;
					}
					for(int k = i+1; k < j; k++){
						dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
					}
				}
			}
			ll ans = 0;
			for(int len = 1; len < n; len++){
				for(int i = 1; i <= n; i++){
					int j = i+len;
					if(d >= x[j]-x[i]){
						f[i][j] = 1;
						continue;
					}
					for(int k = i+1; k < j; k++){
						if(dp[k][j]+dp[i][k] == dp[i][j] && dp[k][j] == 1) f[i][j] += f[k][j]*f[i][k];
					}
				}
			}
			for(int i = 1; i <= n; i++){
				for(int j = i+1; j <= n; j++){
					if(f[i][j] == 2){
						ans++;
					}
				}
			}
			cout << ans << "\n";
			continue;
		}
		if(11 == c || 12 == c){
			unsigned ll k = abs(x[2]-x[1]), q = d/k;
			if(q >= n){
				cout << "0\n";
				continue;
			} 
			if(q == 0 || q == 1){
				cout << "0\n";
				continue;
			}
//			cout << T << " " << k << " " << d << " " << q << " ";
//			cout << n << "\n";
			if(2*q > n){
				cout << "0\n";
				continue;
			}
			cout << (n-2*q+1) << "\n";
			continue;
		}
	}
	return 0;
}
