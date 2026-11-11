#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int c,n,m,d,q,vis[2*N],cnt[2*N];
vector<pair<int,int> > e[2*N];
void di(int u,int v,int fa){
	vis[u] = min(v,vis[u]);
	for(auto [x,y] : e[u]{
		int x = e[u][i].u,y = e[u][i].v;
		if(x==fa)return;
		di(x,v+y,u);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;++i){
		int w;
		cin >> w;
		e[i].push_back({2*i,w});
		e[2*i].push_back({i,w});//1~m是地铁站，m+1~2m是站厅
	}
	for(int i = 1;i<=n;++i){
		int k;
		cin >> k;
		for(int j = 1;j<=k;++j){
			int a,t;
			cin >> a >> t;
			e[a].push_back({2*m+i,t});
			e[2*m+i].push_back({a,t});//2m+1~2m+n是地铁到站厅
		}
	}
	while(q--){
		memset(vis,1e9,2*m);
		int x,y;
		cin >> x >> y;
		di(x,0,0);
		cout << vis[y] << endl;
	}
}
