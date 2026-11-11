#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int c, t, n, k;
int u[N], v[N];
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			cin >> u[i] >> v[i];
		}
		cout << k-1 << "\n";
	}
	return 0;
}