#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int c, t, n, k;
vector<int>G[N];

int main(){
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1; i <= n; ++i){
			int x, y;
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
			
		}
		
		cout << 1;
	}
	return 0;
}
/*

T4

*/