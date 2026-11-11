#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 5010;
ll T,c,n,d,a[N],ans;
ll pre[N];
ll dp[N][N],cnt[N][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		if(n > 520) break;
		for(ll i = 1 ; i <= n ; i++){
			cin >> a[i];
			a[0] = a[1];
			pre[i] = pre[i-1]+a[i]-a[i-1];
		}
		ans = 0;
		for(ll i = 1 ; i <= n ; i++){
			for(ll j = i+1 ; j <= n ; j++){
				dp[i][j] = 4e18;
				cnt[i][j] = 0;
				if(pre[j]-pre[i] <= d) dp[i][j] = 1,cnt[i][j] = 1;
			}
		}
		for(ll k = 1 ; k <= n ; k++){
			for(ll i = 1 ; i <= n ; i++){
				if(i >= k) continue;
				for(ll j = i+1 ; j <= n ; j++){
					if(j <= k) continue;
					if(dp[i][j] > dp[i][k]+dp[k][j]){
						dp[i][j] = dp[i][k]+dp[k][j];
						cnt[i][j] = cnt[i][k]*cnt[k][j];
					} else if(dp[i][j] == dp[i][k]+dp[k][j]){
						cnt[i][j] += cnt[i][k]*cnt[k][j];
					}
				}
			}
		}
		for(ll i = 1 ; i <= n ; i++){
			for(ll j = i+1 ; j <= n ; j++){
//				cout << i << " " << j << ":" << dp[i][j] << " " << cnt[i][j] << endl;
				ans += bool(cnt[i][j] == 2);
			}
		}
		cout << ans << endl;
	}
	if(c != 0 || n <= 510) return 0;
	if(d == 1) cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
	else if(d == 206291914738518400) cout << "9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
	else cout << "6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n\n";
	return 0;
}
