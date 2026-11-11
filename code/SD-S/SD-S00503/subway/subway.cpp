#include <bits/stdc++.h>
#define re register
using namespace std;

const int M = 5e5 + 10,N = 5e2 + 10,ALL = 6e5 + 10;
int ccc,n,m,d,q,delta,w[N],ovo[N][ALL];
vector <int> g[ALL];
long long vis[N][N];
long long min(long long x1,long long x2){
	if(x1 > x2) return x2;
	return x1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	double t1 = clock();
	scanf("%d%d%d%d%d",&ccc,&n,&m,&d,&q);
	for (re int i = 1;i <= m;i ++){
		scanf("%d",&w[i]);
	}
	delta = n + 10;
	for (re int i = 1;i <= n;i ++){
		int k;
		scanf("%d",&k);
		for (re int j = 1;j <= k;j ++){
			int u,v;
			scanf("%d%d",&u,&v);
			
			u = u + delta;
		//	cout << u << " " << v << endl;
			g[u].push_back(i);
			
			g[i].push_back(u);
			ovo[i][u] = v;
			
		}
	}
	//qwq1
	//cout << "qwq1" << endl;
	
	
	for (re int i = 1;i <= n;i ++){
		for (re int now1 = 0;now1 < g[i].size();now1 ++){
			
			int v = g[i][now1],val = ovo[i][g[i][now1]];
			if(g[v].size() == 1) continue;
			for (re int now2 = 0;now2 < g[v].size();now2 ++){
				int qwq = g[v][now2];
				if(qwq == i) continue;
				if((vis[i][qwq] == 0) || (vis[i][qwq] > val + ovo[qwq][v])){
					vis[i][qwq] = val + ovo[qwq][v];
					vis[qwq][i] = val + ovo[qwq][v];
				}
			}
		}
	}
	
	for (re int i = 1;i <= n;i ++){
		for (re int j = 1;j <= n;j ++){
			if(i == j) continue;
			if(vis[i][j] == 0){
				vis[i][j] = 1e18;
			}
		}
	}
	
	for (re int k = 1;k <= n;k ++){
		for (re int i = 1;i <= n;i ++){
			if(i == k) continue;
			for (re int j = 1;j <= n;j ++){
				if(i == j || j == k) continue;
				vis[i][j] = min(vis[i][j],vis[i][k] + vis[k][j]);
			}
		}
	}
//	}
//	double t2 = clock();
//	cout << endl<< t2 - t1 << endl;
	//qwq2
	//cout << "qwq2" << endl;
	
	
	while(q --){
		int x,y;
		scanf("%d%d",&x,&y);
		long long res = w[x] + w[y]; 
		x = x + delta;
		y = y + delta;
		long long ans = 1e18;
		for (re int now1 = 0;now1 < g[x].size();now1 ++){
			int qwq = g[x][now1];
			if(ovo[qwq][x] >= ans) continue;
			for (re int now2 = 0;now2 < g[y].size();now2 ++){
				int pwp = g[y][now2];
				ans = min(vis[qwq][pwp] + ovo[qwq][x] + ovo[pwp][y],ans);
				if(ans == 0) break;
			} 
			if(ans == 0) break;
		}
		ans += res;
		printf("%lld\n",ans);
	}
	
	return 0;
}
