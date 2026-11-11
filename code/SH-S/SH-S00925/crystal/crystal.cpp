#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll n,m,a[N],s[N];
void input() {
	cin>>n>>m;
	for(ll i = 1;i <= n;i++) cin>>a[i];
}
void solve() {
	sort(a + 1,a + n + 1);
	for(ll i = 1;i <= n;i++) {
		s[i] = s[i - 1] + a[i];
	}
	ll ans = 0;
	for(ll i = 1,j = 1;i <= n;i++) {
		while(j <= i && (a[i] * (i - j + 1) - (s[i] - s[j - 1])) > m) j++;
		ans = max(ans,i - j + 1);
	}
	cout<<ans<<'\n';
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	solve();
	return 0;
}
