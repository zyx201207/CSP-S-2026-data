#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N = 555, M = 5e5 + 10;
vector<int> zt_have[M], xl_have[N];
int nd[N][N];
int L[N * N];
int w[M];
int n, m;
int d, q;

namespace Work{
	
	int cost[N][N];
	
	void work(){
		scanf("%lld%lld", &n, &m);
		
		scanf("%lld", &d);
		
		scanf("%lld", &q);
		
		for (int i = 1; i <= m; i++) scanf("%lld", &w[i]);
		
		for (int i = 1; i <= n; i++){
			int k;
			scanf("%lld", &k);		
			
			for (int j = 1; j <= k; j++){
				int zt;
				scanf("%lld", &zt);
				scanf("%lld", &cost[zt][i]);
				xl_have[i].push_back(zt);
				zt_have[zt].push_back(i);
			}
			
		}
		
		while(q--){
			for (int i = 1; i <= m; i++){
				for (int j = 1; j <= m; j++){
					nd[i][j] = INT_MAX;
				}
			}
			
			int x, y;
			scanf("%lld%lld", &x, &y);

			int head = 1, last = 1;
			L[1] = x;
			
			nd[x][x] = 0;
						
			while(head <= last){
				int top = L[head++];

				for (int i = 0; i < zt_have[top].size(); i++){
					int u = zt_have[top][i];
					
					for (int j = 0; j < xl_have[u].size(); j++){
						int v = xl_have[u][j];
						if (nd[x][v] <= nd[x][top] + cost[top][u] + cost[v][u]) continue;
						else {
							nd[x][v] = nd[x][top] + cost[top][u] + cost[v][u];
							L[++last] = v;
						}
					}
				}
			}

			printf("%lld\n", w[x] + w[y] + nd[x][y]);
		}
		
	}
}

namespace WorkB{
	int cost;
	
	void work(){
		scanf("%lld%lld", &n, &m);
		
		scanf("%lld", &d);
		
		scanf("%lld", &q);
		
		for (int i = 1; i <= m; i++) scanf("%lld", &w[i]);
		
		for (int i = 1; i <= n; i++){
			int k;
			scanf("%lld", &k);		
			
			for (int j = 1; j <= k; j++){
				int zt;
				scanf("%lld%lld", &zt, &cost);
				xl_have[i].push_back(zt);
				zt_have[zt].push_back(i);
			}
		}
		
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++) nd[i][j] = -1;
			
			nd[i][i] = 0;
			
			int head = 1, last = 1;
			L[1] = i;
			
			while(head <= last){
				int top = L[head++];
				
				for (int j = 0; j < xl_have[top].size(); j++){
					int u = xl_have[top][j];
					for (int k = 0; k < zt_have[u].size(); k++){
						int v = zt_have[u][k];
						if (nd[i][v] != -1) continue;
						
						nd[i][v] = nd[i][top] + 1;
						
						L[++last] = v;
					}
				}
			}
			
		}		
		
		while(q--){
			int ans = LLONG_MAX;
			int x, y;
			scanf("%lld%lld", &x, &y);
			
			for (int i = 0; i < zt_have[x].size(); i++){
				for (int j = 0; j < zt_have[y].size(); j++){
					int u = zt_have[x][i], v = zt_have[y][j];
					
					ans = min(ans, nd[u][v]);
				}
			}
		
			printf("%lld\n", w[x] + w[y] + ans * cost);
		}
		
	}
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	int id;
	scanf("%lld", &id);
	
	if (id >= 12 && id <= 19){
		WorkB::work();
	}
	else{
		Work::work();
	}

	return 0;
}