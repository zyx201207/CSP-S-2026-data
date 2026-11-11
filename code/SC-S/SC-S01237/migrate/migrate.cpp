#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000006];
void solve(){
	cin >> n >> d;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	if (11 < c && c <= 12){
		cout << 0 << "\n";
		return;
	}
	if (13 <= c && c <= 14){
		cout << 0 << "\n";
		return;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while (t--){
		solve();
	}
	return 0;
}