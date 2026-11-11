#include <bits/stdc++.h>
using namespace std;

long long c, t, n, d, a[10004], p[10004], ans, w[10004];
void dfs(int k, int l, int s){
	if(l > n) return ;
//	cout << k << ' ';
	if(s != 0 && s <= w[l]) p[l]++;
	for(int i = 1; i <= d; i++){
		for(int j = 1; j <= n; j++){
			if(a[j] == k + i) dfs(k + i, j, s + 1);
		}
	}
	return ;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int j = 1; j < n; j++){
			for(int i = j; i <= n; i++) w[i] = ceil((double)(a[i] - a[j]) / d);
			memset(p, 0, sizeof p);
			dfs(a[j], j, 0);
//			cout << endl;
			for(int i = 1; i <= n; i++){
//				cout << p[i] << ' ';
				if(p[i] == 2){
//					cout << i << "IGGGUYGYUFTYFUIFTYUF\n";
					ans++;
				} 	
			} 
//			cout << '\n';	
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/