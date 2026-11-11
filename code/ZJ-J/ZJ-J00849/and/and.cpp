#include <bits/stdc++.h>
using namespace std;
const long long N = 2005;
long long a[200005], dp[N][N], n, m, mx, power[35];
bool check_A(){
	bool f;
	for (long long i = 1; i <= n; i++){
		f = false;
		for (long long j = 1; j <= 30; j++){
			if (a[i] + 1 == power[j]){
				f = true;
				break;
			}
		}
		if (!f) return false;
	}
	return true;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	power[0] = 1;
	for (long long i = 1; i <= 30; i++) power[i] = power[i - 1] * 2;
	if (n <= 2000){
		for (long long i = 1; i <= n; i++) dp[i][1] = a[i];
		for (long long i = 1; i <= n; i++){
			for (long long j = 2; j <= m; j++){
				for (long long k = 1; k <= i - 1; k++){
					dp[i][j] = max(dp[i][j], dp[k][j - 1] & a[i]);
				}
			}
		}
		for (long long i = 1; i <= n; i++) mx = max(mx, dp[i][m]);
		cout << mx;
	} else if (m == n - 1){
		long long ans = 0, sum;
		for (long long i = 2; i <= n; i++){
			sum = a[1];
			for (long long j = 2; j <= n; j++){
				if (i == j) continue;
				sum &= a[i];
			}
			ans = max(ans, sum);
		}
		sum = a[2];
		for (long long i = 3; i <= n; i++) sum &= a[i];
		cout << max(ans, sum);
	} else if (check_A()){
		sort(a + 1, a + n + 1, greater<long long>());
		cout << a[m];
	} else {
		sort(a + 1, a + n + 1, greater<long long>());
		long long sum = a[1];
		for (long long i = 2; i <= m; i++) sum &= a[i];
		cout << sum;
	}
	return 0;
}