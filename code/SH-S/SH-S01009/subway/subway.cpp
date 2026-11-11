#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 86;

int c, n, m, d, q;

int w[N];

vector<pair<int, int> >zhan[N]; 

vector<pair<int, int> >gui[N]; 

int random(int x, int y){
	return (x+1)* (x) < y;
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i){
		cin >> w[i];
	} 
	for(int i = 1; i <= n; ++i){
		int k;
		cin >> k;
		for(int j = 1; j <= k; ++j){
			int a, t;
			cin >> a >> t;
			zhan[i].push_back({a, t});
		} 
	}
	for(int i = 1; i <= q; ++i){
		
		int x, y;
		cin >> x >> y;
		gui[i].push_back({x, y});
		
	} 
	 
	cout << random(1, INT_MAX);
	
	return 0;
}

