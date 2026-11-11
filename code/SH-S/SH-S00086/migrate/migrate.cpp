#include<bits/stdc++.h>
typedef long long ll;
const int N = 2e6 + 5;
ll x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::cin.tie(0)->sync_with_stdio(0);
	int c,t;
	for (std::cin >> c >> t;t--;){
		int n;ll d;std::cin >> n >> d;
		for (int i = 1;i <= n;i++) std::cin >> x[i];
		if (c == 11 || c == 12){
			if (n <= 2) std::cout << 0 << '\n';
			else{
				ll y = x[2] - x[1];
				if (2 * y > d) std::cout << 0 << '\n';
				else std::cout << std::max(0ll,n - (2 * (d / y) - 1)) << '\n';
			}
			continue;
		}
		ll ans = 0;
		for (int u = 1;u < n;u++)
			for (int v = u + 1;v <= n;v++){
				int now = u;
				std::vector<int> nd;
				nd.push_back(u);
				bool conn = 1;
				while (now <= v){
					int fAr = std::upper_bound(x + 1,x + 1 + n,x[now] + d) - x - 1;
					if (fAr >= v){
						nd.push_back(v);
						break;
					}
					if (fAr == now){
						conn = 0;
						break;
					}
					nd.push_back(now = fAr);
				}
				if (!conn) continue;
				bool flag = 0,fst = 1;
				for (int i = nd.size() - 2;i >= 0;i--){
					if (nd[i] - 1 >= u && x[nd[i + 1]] <= x[nd[i] - 1] + d){
						if (!flag && fst) flag = 1,fst = 0;
						else if (!fst){
							flag = 0;
							break;
						}
					} 
					if (nd[i] - 2 >= u && x[nd[i + 1]] <= x[nd[i] - 2] + d){
						flag = 0;
						break;
					} 
				}
				if (flag) ++ans;
			}
		std::cout << ans << '\n';
	} 
	return 0;
}
