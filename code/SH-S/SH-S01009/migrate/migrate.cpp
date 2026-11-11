#include<bits/stdc++.h>
#define int long long

const int N = 2e6 + 86;

using namespace std;

int c, t;

int x[N];

int pingfang(int x, int y){
	return (x-y) * (x-y);
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for(int j = 1; j <= t; ++j){
		memset(x, 0, sizeof(x));
		int n;
		int d;
		int ans = 0;
		int cnt = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; ++i){
			cin >> x[i];
		}
		for(int i = n; i >= 1; --i){
			for(int z = 1; z < i; ++z){
				int xx = pingfang(x[i], x[z]);
				if(xx <= d * d){
					continue;
				}else{
					for(int k = 1; k <= n; ++k ){
						
						if(k == z || k == i){
							continue;
						}else{
							int x1 = pingfang(x[k], x[z]);
							int x2 = pingfang(x[k], x[i]);
							if(x1 <= d * d && x2 <= d*d){
								ans++;
							}	
						}
					}
					
					if(ans == 2){
						cnt++;
					}	
				}
			}
		}
		
		cout << cnt; 
	}
	return 0;
}
