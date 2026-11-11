#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5;
int n;
ll m, a[MAXN], dp[MAXN][2];
int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	dp[1][0] = 1; dp[1][1] = m; int p = 1;
	for(int i = 2; i <= n; i++){
		dp[i][0] = dp[i - 1][0] + 1;
		dp[i][1] = dp[i - 1][1] - (i - p) * (a[i] - a[i - 1]);
		while(dp[i][1] < 0){
			dp[i][0]--;
			dp[i][1] += (a[i] - a[p]);
			p++;
		}
	}
	ll mx = 0;
	for(int i = 1; i <= n; i++){
		mx = max(mx, dp[i][0]);
	}
	cout << mx;
	return 0;
}