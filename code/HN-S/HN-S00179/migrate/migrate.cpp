#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int c, t, ans;
ll x[10000000];

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		int n, d;
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
		cout << (n + 1) * n / 2 << '\n';
	}
	return 0;
}
/*
0 1
4 3
1 2 3 4
*/
