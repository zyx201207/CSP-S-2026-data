#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
ll c,t,n,d,x[N];
void input() {
	cin>>n>>d;
	for(ll i = 1;i <= n;i++) cin>>x[i];
}
ll f[5005][5005],len[5005],s[5005];
void solve1() {
	for(ll i = 1;i <= n;i++) {
		for(ll j = 1;j <= n;j++) f[i][j] = 0;
		f[i][i] = 1;
	}
	ll ans = 0;
	for(ll i = 2;i <= n;i++) {
		for(ll j = i - 1;j >= 1;j--) {
			len[j] = 1e18; s[j] = 0;
		}
		len[i] = 0; s[i] = 1; s[i + 1] = 0;
		ll curl = i,curr = i;
		for(ll j = i - 1;j >= 1;j--) {
			while(j <= curr && x[curr] - x[j] > d) curr--;
			if(curr == j) break;
			while(curl > j + 1 && len[curl - 1] == len[curr]) curl--;
			if(curr < curl) break;
			f[i][j] = s[curl] - s[curr + 1];
			s[j] = s[j + 1] + f[i][j];
			len[j] = len[curr] + 1;
//			cout<<x[curr] - x[j]<<" "<<d<<" "<<i<<" "<<j<<" "<<curl<<" "<<curr<<" "<<f[i][j]<<'\n';
			if(f[i][j] == 2) ans++;
		}
	}
	cout<<ans<<'\n';
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--) {
		input();
		if(n <= 5000) solve1();
	}
	return 0;
}
