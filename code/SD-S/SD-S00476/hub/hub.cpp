#include <bits/stdc++.h>
const int N = 1e6 + 50;
int n , k;
std::vector<int>edg[N];
int tag[N];
bool vs[N];
void dfs(int u,int tg){
	if(!vs[u])return;
	if(tag[u]!=-1)return;
	tag[u] = tg;
	for(int it : edg[u]){
		if(vs[it])dfs(it,tg);
	}
}
int used[N];
signed main(){
	freopen("hub.in" , "r", stdin);
	freopen("hub.out", "w", stdout);
	int c , t;scanf("%d%d", &c, &t);
	while(t -- ){
		for(int i = 1 ;i <= n ; ++ i){
			edg[i].clear();
		}
		scanf("%d%d", &n, &k);
		for(int i = 1 ; i < n ; ++ i){
			int u , v;
			scanf("%d%d",&u,&v);
			edg[u].push_back(v);
			edg[v].push_back(u);
		}
		int as = n;
		for(int i = 0 ; i < ( 1 << (n)) ; ++ i){
			int ct = 0;
			for(int j=1;j<=n;++j)vs[j]=false;
			for(int j = 0 ; j < n ; ++ j){
				if((i >> j) & 1)ct ++ ,tag[j + 1] = -1,vs[j+1]=true;
			}
			if(ct != k) continue;
			for(int j=1;j<=n;++j)used[j]=-1;
			int cc = 0;
			for(int j = 1 ; j <= n ; ++ j){
				if(vs[j]){
					if(tag[j]==-1){
						dfs(j , ++cc);
					}
				}
			}
			if(cc > 2) continue;
			std::queue<std::pair<int,int>> qu;
			for(int j = 0 ; j < n ; ++ j){
				if(((i >> j) & 1)){
					vs[j]=true;
					qu.push({j + 1 , 0});
				}
			}
			if(ct != k) continue;
			while(!qu.empty()){
				auto tp = qu.front();
				qu.pop();
				if(used[tp.first] == -1){
					used[tp.first] = tp.second;
					for(int it : edg[tp.first]){
						qu.push({it , tp.second + 1});
					}
				}
			}
			int mx = 0;
			for(int j = 1 ; j <= n ; ++ j){
				mx = std::max(mx , used[j]);
			}
			as = std::min(as , mx);
		}
		printf("%d\n",as);
	}
	return 0;
}
