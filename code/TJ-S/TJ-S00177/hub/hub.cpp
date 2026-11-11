#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	for(int i = 1;i<=n-1;i++){
		int u, v;
		cin >> u >> v;
	}
	if(k==n) cout << 0 << "\n";
	else{
		int m = n/2;
		cout << m/k << "\n";
	}
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--) solve();
	return 0;
}
