#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 3;
int a[N]; 
signed main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out", "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c , t;
	cin >> c >> t;
	while(t --){
		int n , d; cin >> n >> d;
		for(int i = 1; i <= n; ++ i){
			cin >> a[i];
		}
		if(11<=c&&c<=12){
			int len = 0;
			while(len < n && a[1 + len] <= a[1] + d) ++ len;
			-- len;
			if(!len || len == 1){
				cout << 0 << '\n';
				continue;
			}
			int ans = 0;
			for(int i = 1; i <= n; ++ i){
				if(i + 2 * len - 1 <= n) ++ ans;
			}
			cout << ans << '\n';
			continue;
		}
		int www = 0;
		for(int u = 1; u <= n; ++ u){
			vector<int> w;
			int ans = 0;
			w . emplace_back(u); w . emplace_back(u + 1);
			bool flg = (a[u + 1] - a[u] <= d);
			for(int v = u + 2; v <= n && flg; ++ v){
				flg &= a[v] - a[v - 1] <= d;
				if(!flg) break;
				w . emplace_back(v);
				int len = w . size() - 1;
				if(a[w[len]] - a[w[len - 2]] <= d){
					w[len - 1] = w[len];
					w . pop_back();
					len = w . size() - 1;
				}
				else{
					len = w . size() - 1;
					//cerr << u << ' '<< len << '\n';
					int i = len - 3;
					if(i >= 0)
						for(int k = w[i + 1] - 1; k >= w[i]; -- k){
							if(a[k] >= a[w[i + 2]] - d){
								++ ans;
								if(ans >= 2) break;
							}
							else break;
						}	
				}
				if(ans >= 2) break;
				len = w . size() - 1;
				int tot = ans;
				for(int i = max(len - 2, 0LL); i + 2 < w . size(); ++ i){
					for(int k = w[i + 1] - 1; k >= w[i]; -- k){
						if(a[k] >= a[w[i + 2]] - d){
							++ tot;
							if(tot >= 2) break;
						}
						else break;
					}
				}
				if(tot == 1) ++ www;
			}
		}
		cout << www << '\n';
	}
	return 0;
}

