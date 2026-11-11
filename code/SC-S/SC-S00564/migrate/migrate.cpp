#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	int c, t;
	cin >> c >> t;
	while(t --){
		int n, d;
		cin >> n >> d;
		vector<int> a(n + 5);
		int g = -1;
		for(int i = 1; i <= n; i ++){
			cin >> a[i];
			g = max(g, a[i] - a[i - 1]);
			if(i == 1) g = -1;
		}
		if(d / g <= 1){
			cout << "0\n";
		} else {
			int k = d / g;
			cout << (a[n] - a[1]) / k << '\n';
		}
	}
}