#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int head[1000005],c,n,m,d,q,w[500005],idx,f[600][600],me[100005],cnt;
struct Pass{
	int lin,t;
};
vector<Pass> dot[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	memset(head,-1,sizeof(head));
	memset(f,0x3f,sizeof(f));
	cin >> c >> n >> m >> d >> q;
	int a,t,k;
	for (int i = 1;i <= n;i ++) f[i][i] = 0;
	for (int i = 1;i <= m;i ++) cin >> w[i];
	for (int i = 1;i <= n;i ++){
		cin >> k;
		for (int j = 1;j <= k;j ++){
			cin >> a >> t;
			dot[a].push_back({i,t});
		}
	}
	for (int i = 1;i <= m;i ++){
		for (int j = 0;j < dot[i].size();j ++){
			for (int k = j + 1;k < dot[i].size();k ++){
				int u = dot[i][j].lin,v = dot[i][k].lin;
				f[u][v] = dot[i][j].t + dot[i][k].t;
				f[v][u] = dot[i][j].t + dot[i][k].t;
			}
		} 
	}
	for (int k = 1;k <= n;k ++){
		for (int i = 1;i <= n;i ++){
			for (int j = 1;j <= n;j ++){
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
			} 
		}
	}
	while (q --){
		int x,y;cin >> x >> y;
		int minn = 0x3f3f3f3f;
		int dx = dot[x].size(),dy = dot[y].size();
		for (int i = 0;i < dx;i ++){
			for (int j = 0;j < dy;j ++){
				Pass f1 = dot[x][i],t1 = dot[y][j];
				minn = min(minn,f[f1.lin][t1.lin] + f1.t + t1.t);
			}	
		}
		cout << minn + w[x] + w[y] << '\n';
	}
	return 0;
}

