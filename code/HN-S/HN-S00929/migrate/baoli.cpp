#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define __low lower_bound
#define __upp upper_bound
#define pii pair<int,int>
#define MP make_pair
#define fi first
#define se second
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5e3+5;

int c, T, n;
ll d, a[N];
int ans;

int dis[N][N];
ll dp[N][N];

void init(){
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			dp[i][j] = dp[j][i] = 1;
			if(abs(a[i] - a[j]) <= d) dis[i][j] = dis[j][i] = 1;
			else dis[i][j] = dis[j][i] = 1e9;
		} 	
		dis[i][i] = 0;
	}
}

void flo(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				if(dis[i][k] + dis[j][k] < dis[i][j]){
					dis[i][j] = dis[j][i] = dis[i][k] + dis[j][k];
					dp[i][j] = dp[j][i] = dp[i][k] * dp[j][k];
				} else if(dis[i][k] + dis[j][k] == dis[i][j]){
					dp[i][j] = dp[j][i] = dp[i][j] + dp[i][k] * dp[j][k];
				}
				if(dp[i][j] > 1e9) dp[i][j] = dp[j][i] = 1e9;
			}
		}
	}
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("baoli.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> c >> T;
	while(T--){
		ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		sort(a+1, a+1+n);
		init();
		flo();
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				if(dp[i][j] == 2) ans++;
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
} 
