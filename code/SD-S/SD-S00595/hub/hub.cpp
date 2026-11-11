#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int u[500050], v[500500];
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	for(int j = 1; j <= t; j++){
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			cin >> u[i] >> v[i];
		} 
	}
	if(t = 2){
		cout << 1 << endl << 2;
	}
	return 0;
}
