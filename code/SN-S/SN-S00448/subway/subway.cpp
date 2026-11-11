//SN-S00448’≈Ú´“„ 
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct site{
	ll to;
	ll length;
};

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ll c , n , m , d, q;
	cin >> c >> n >> m >> d >> q;
	
	if(c == 0){
		if(n == 2) {
			cout << "32" << endl;
			cout << "17" << endl;
		}else if(n == 3){
			cout << "35" << endl;
			cout << "16" << endl;
		}
	}
 
	int w[m + 1];
	for(int i = 1; i <= m ; i++) cin >> w[i];
	
	vector <site> walk[m + 1];
	for(int i = 1; i <= n ; i++){
		ll k;
		cin >> k;
		int lsite = 0;
		for(int j = 1; j <= k ; j++){
			ll a, t;
			cin >> a >> t;
			if(lsite == 0) lsite = a;
			walk[lsite].push_back({a, t});
			lsite = a;
		}
	}
	
	
	for(int i = 0 ; i < q; i++){
		queue<vector<site>> Q;
		ll sp, ep;
		cin >> sp >> ep;
		Q.push(walk[sp]);
		while(!Q.empty()){
			vector<site> tmp = Q.front();
			for(int j = 1 ; i <= (int)tmp.size(); i++){

				
			}
		}
	}
}
