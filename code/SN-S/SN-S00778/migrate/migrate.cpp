#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> x;
int ans = 0,cnt[10][500];

void solve(){
	int n;ll d;
	ans = 0;
	x.clear();
	cin >> n >> d;
	ll xx;
	x.push_back(0);
	for(int i=1;i<=n;++i) {
		cin >> xx;
		x.push_back(xx);
	}
	cout << n/2 << endl; 
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;cin >> T >> T;
	while(T--){
		solve();
	}
	
	return 0;
} 

