#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500005;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,k[N];
ll F[505][505],w[N];
struct edge{int v;ll w;};
vector<edge> e[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q; 
	for(int i=1;i<=m;++i)cin >> w[i];
	for(int i=1;i<=n;++i){
		cin >>  k[i];
		for(int j=1;j<=k[i];++j){
			int a,t;cin >> a >> t;
			e[a].push_back({i,t});
		}
	}
	memset(F,0x3f,sizeof(F));
	for(int i=1;i<=n;++i)F[i][i] = 0;
	for(int i=1;i<=m;++i){
		int all = (int)e[i].size();
		for(int x=0;x<all;++x)
			for(int y=0;y<all;++y){
				int u = e[i][x].v,v = e[i][y].v;
				F[u][v] = min(F[u][v],e[i][x].w + e[i][y].w);
			}
	} 
	for(int x=1;x<=n;++x)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				F[i][j] = min(F[i][j],F[i][x]+F[x][j]);
	for(int i=1;i<=q;++i){
		int x,y;cin >> x>>y;
		if(x==y){cout<<0<<"\n";continue;}
		ll minn = inf;
		for(edge o1:e[x])
			for(edge o2:e[y]){
				minn = min(minn,o1.w+o2.w+F[o1.v][o2.v]);
			}
		cout<<minn + w[x] + w[y]<<"\n"; 
	}
	return 0;
} 
