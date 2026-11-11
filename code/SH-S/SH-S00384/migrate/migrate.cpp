#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
const int N1 = 305;
int c,T,n;
ll x[N],d;
int G[N1][N1],cnt[N1][N1];
void solve(){
	cin >> n >> d;
	for (int i = 1;i <= n;i++) cin >> x[i];
	if (c == 11 || c == 12){
		ll tmp = x[2] - x[1];
		ll k = d / tmp;
		if (k < 2) cout << 0 << '\n';
		else cout << max(0ll,n - 2 * k + 1) << '\n';
		return;
	}
	memset(G,0x3f,sizeof(G));
	memset(cnt,0,sizeof(cnt));
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= n;j++){
			if (i == j) continue;
			if (abs(x[i] - x[j]) > d) continue;
			G[i][j] = G[j][i] = 1;
			cnt[i][j] = cnt[j][i] = 1;
		}
	}
	for (int i = 1;i <= n;i++) G[i][i] = 0;
	for (int k = 1;k <= n;k++){
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= n;j++){
				if (G[i][k] + G[k][j] < G[i][j]){
					cnt[i][j] = cnt[i][k] * cnt[k][j];
					G[i][j] = G[i][k] + G[k][j];
				}
				else if (G[i][j] == G[i][k] + G[k][j]){
					cnt[i][j] += cnt[i][k] * cnt[k][j];
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= n;j++){
			if (i == j) continue;
			if (cnt[i][j] == 2) ans++;
		}
	}
	cout << ans / 2 << '\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> T;
	while (T--) solve();
}
