#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N = 600 + 10;

int T, n, c, f[N], ans;

long long a[N], G[N], d;

int main(){
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> T;
	while(T--){
		cin >> n >> d; ans = 0;
		for(int i = 1; i <= n; i++)cin >> a[i];
		for(int i = 1; i <= n; i++){
			memset(f, 0, sizeof(f));
			memset(G, 0x3f3f3f3f, sizeof(G));
			G[i] = 0;
			for(int j = i + 1; j <= n; j++){
				for(int k = j; k >= i; k--){
					if(a[j] - a[k] <= d){
						if(G[k] + 1 < G[j]){
							f[j] = 1;
							G[j] = G[k] + 1;
						}
						else if(G[k] + 1 == G[j]){
							f[j]++;
						}
					}
				}
				if(f[j] == 2)ans++;
				//cout << i << " " << j << " " << f[j] << "\n";
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}

/*

0 2
4 2 
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
