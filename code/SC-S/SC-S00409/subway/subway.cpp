#include <iostream>
#include <map>
#include <vector>

const int N = 5e5 + 99;

int c, n, m, d, q;
int w[N];
std::map < int, long long> edge[N];

namespace A{

	void solve() {
		
		for(int i = 1; i <= m; i++)
			std::cin >> w[i];
		
		for(int i = 1; i <= n; i++) {
			
			int k;
			std::cin >> k;
			std::vector <int> way, ti;
			
			for(int j = 1; j <= k; j++) {
				long long a, t;
				std::cin >> a >> t;
				
				for(int i = 0; i*1ull < way.size(); i++) {
					if(edge[a].count(way[i])) {
						
						int temp = std::min( edge[a][way[i]], t+ti[i]);
						edge[a][way[i]] = edge[way[i]][a] = temp;
						
					}
					else {
						int temp = t+ti[i];
						edge[a][way[i]] = edge[way[i]][a] = temp;
					}
				}
				
				way.push_back(a), ti.push_back(t);
				
			}
			
		}	
		
//		for(int i = 1; i <= m; i++){
//			std::cout << i << '\n';
//			for(auto x:edge[i]) {
//				
//				std::cout << x.first << ' ' << x.second << '\n';
//				
//			}
//		}
		
		for(int k = 1; k <= m; k++)
			for(int i = 1; i <= m; i++)
				for(int j = 1; j <= m; j++){
					
					if( !edge[i].count(k) || !edge[k].count(j) )continue;
					
					long long temp = edge[i][k] + edge[k][j];
					
					if(edge[i].count(j))
						edge[i][j] = std::min( edge[i][j], temp);
					else
						edge[i][j] = temp;
					
				}
		
		while(q--) {
			
			int l, r;
			std::cin >> l >> r;
			std::cout << w[l] + w[r] + edge[l][r] << '\n';
			
		}
		
	}
	
}

int main() {
	
	freopen( "subway.in", "r", stdin);
	freopen( "subway.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> c >> n >> m >> d >> q;
	A::solve();
	return 0;
	
}