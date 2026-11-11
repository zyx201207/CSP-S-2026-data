#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read() {
	ll res = 0, neg = 1; char ch = getchar();
	while(ch<'0' or ch>'9') { if(ch == '-') neg = -1; ch = getchar(); }
	while(ch>='0' and ch<='9') res = res*10 + ch-'0', ch = getchar();
	return res * neg;
}

void write(ll x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x+'0');
	else write(x/10), putchar(x%10+'0');
}

const int N = 510, M = 5e5+10, Q = 1e5+10;

int n,m,d,q;
ll outw[M];

struct Querys {
	int u,v; ll ans;
} qrys[Q];

struct Tp {
	int v; ll w;
}; vector<Tp> sons[M];

ll dis[N][N];

ll ptsdis[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int C = read();
	n = read(), m = read(), d = read(), q = read();
	
	for(int i=1; i<=m; i++) outw[i] = read();
	
	for(int i=1; i<=n; i++) {
		int tk = read();
		while(tk--) {
			int u = read(); ll w = read();
			sons[u].push_back( (Tp){i,w} );
		}
	}
	
	for(int i=1; i<=q; i++) {
		qrys[i].u = read(), qrys[i].v = read();
		qrys[i].ans = 2e18;
	}
	
	memset(dis, 0x3f, sizeof(dis));
	for(int i=1; i<=n; i++) dis[i][i] = 0;
	
	for(int i=1; i<=m; i++) {
		int k = sons[i].size();
		
		for(int id1=0; id1<k; id1++)
			for(int id2=id1+1; id2<k; id2++) {
				int u = sons[i][id1].v, v = sons[i][id2].v;
				ll w = sons[i][id1].w + sons[i][id2].w;
				
				dis[u][v] = min(dis[u][v], w);
				dis[v][u] = min(dis[v][u], w);
			}
	}
	
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	
//	for(int i=1; i<=n; i++)
//		for(int j=1; j<=n; j++) printf("%d %d %lld\n", i,j,dis[i][j]);
	
	for(int k=1; k<=n; k++) {
		memset(ptsdis, 0x3f, sizeof(ptsdis));
//		for(int i=1; i<=m; i++) ptsdis[i] = 2e18;
		
		for(int i=1; i<=m; i++)
			for(Tp tmp : sons[i]) {
				int v = tmp.v; ll w = tmp.w;
				ptsdis[i] = min(ptsdis[i], w + dis[v][k]);
			}
			
//		printf("#%d\n", k);
//		for(int i=1; i<=m; i++) printf("%d %lld\n", i,ptsdis[i]);// puts("");
		
		for(int i=1; i<=q; i++) {
			int u = qrys[i].u, v = qrys[i].v; //printf("%d %d %d\n",i,u,v);
			qrys[i].ans = min(qrys[i].ans, ptsdis[u] + ptsdis[v]);
		}
	}
	
	for(int i=1; i<=q; i++) {
		int u = qrys[i].u, v = qrys[i].v;
		write(qrys[i].ans + outw[u] + outw[v]), putchar('\n');
	}
	
	return 0;
}
