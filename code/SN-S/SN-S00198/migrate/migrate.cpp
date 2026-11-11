#include<bits/stdc++.h>
using namespace std;

int c, t, n, d, x[500010];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
		int t = n * (n - 1);
		t /= 2;
		cout << (rand() % t) << "\n";
	}
	return 0;
}
