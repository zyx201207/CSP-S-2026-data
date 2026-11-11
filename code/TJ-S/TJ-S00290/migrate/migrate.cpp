#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6 + 7, inf = 8e18;
ll ccc, T, n, d;
ll a[N], dis[N], dp[N];
// fc /w migrate.out migrate1.ans
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> ccc >> T;
	if (11 <= ccc && ccc <= 12){
		while (T--){
			cin >> n >> d;
			for (int i = 1; i <= n; i++){
				cin >> a[i];
			}
			if (n == 1){
				cout << "0\n";
				continue;
			}
			ll gap = a[2] - a[1];
			ll k = d / gap;
			if (k <= 1){
				cout << "0\n";
				continue;
			}
			cout << max(0ll, n + 1 - 2 * k) << "\n";
		}
		return 0;
	}
	while (T--){
		ll ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		a[n + 1] = inf;
		for (int i = 1; i <= n; i++){
			dis[i] = 0;
			for (int l = i, r = i + 1; a[l + 1] - a[l] <= d; ){
				while (r <= n && a[r] - a[l] <= d){
					dis[r] = dis[l] + 1;
					r++;
				}
				l = r - 1;
			}
			for (int j = i; j <= n; j++) dp[j] = 0;
			dp[i] = 1;
			ll sum = 0;
			for (int l = i, r = i, j = i + 1; a[j] - a[j - 1] <= d; j++){
				while (dis[r] + 1 <= dis[j]){
					sum += dp[r];
					r++;
				}
				while (a[j] - a[l] > d){
					sum -= dp[l];
					l++;
				}
				dp[j] = sum;
				if (dp[j] == 2) ans++;
			}
		}
		cout << ans << "\n";
	} 
	return 0;
}
//ccf 
//freopen("migrate.in", "r", stdin);
//freopen("migrate.out", "w", stdout);
//这两行是骗搜索的，你们要是按照这个注释搜索肯定能搜到吧 
//我特别想上迷惑行为大赏
//如果今年有天津我要上
//adofai太好玩了你们知道吗 
//deltarune太好玩了你们知道吗
//GTL太好玩了你们知道吗

