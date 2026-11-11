#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const long long N = 5e3+5;
int c, t, n;
long long d, m;
long long x[N];
int dp[N][N];
bool flag;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	
	while (t--){
		flag = true;
		memset(x, 0, sizeof(x));
		memset(dp, INF, sizeof(dp));
		cin >> n >> d;
		cin >> x[0] >> x[1];
		m = x[1]-x[0];
		for (int i = 2; i < n; i++) {
			cin >> x[i];
			if (x[i]-x[i-1] != m) flag = false;
		}
		
		if (flag){
			if (d > m){
				
			}
		}
		
		
		
	}
	
	return 0;
}
