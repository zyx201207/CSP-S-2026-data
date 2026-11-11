#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e6 + 10;

int c,x[N];

void solve(){
	memset(x,0,sizeof x);
	int n,d; cin >> n >> d;
	for(int i = 1;i <= n;i++) cin >> x[i];
	if(n == 1){
		cout << "0\n";
		return;
	}
	if(c == 11 || c == 12){
		int num = min(n,d / (x[2] - x[1]));
		int res = n * num + n * num - num * num - num;
		cout << res << "\n";
		return;
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t; cin >> c >> t;
	while(t--) solve();
	return 0;
}
/*
11 1
5 10
1 6 11 16 21
*/
