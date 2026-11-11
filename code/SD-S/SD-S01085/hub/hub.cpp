#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, k;
void solve(){
	cin >> n >> k;
	for(int i = 1;i < n;i++){
		int x, y;
		cin >> x >> y;
	}
	if(n == k){
		cout << "0\n";
	}
	else{
		cout << "1\n";
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--) solve();
	return 0;
}

