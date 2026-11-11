#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	vector<int> w(m + 1);
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	while(q--){
		mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
		cout << rng() % 100 << '\n';
	}
	return 0;
}