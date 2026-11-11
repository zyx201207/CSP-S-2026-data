#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500+5,M=5e5+5;
const ll INF=1e18;
int cid;
int n,m,d,q;
ll f[N][N];
void floyd(){
	for (int k=1;k<=n;++k){
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}
int w[M];
vector<pair<int,int>> g[M];//每个站点的信息
void solve(){
	cin >> n >> m >> d >> q;
	for (int i=1;i<=m;++i) cin >> w[i];
	for (int i=1,k;i<=n;++i){
		cin >> k;
		for (int j=1,a,t;j<=k;++j){
			cin >> a >> t;
			g[a].emplace_back(i,t);
		}
	}
	for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) f[i][j]=INF;
	for (int i=1;i<=n;++i) f[i][i]=0;
	ll wt;
	for (int i=1,a,b,u,v;i<=m;++i){
		for (a=0;a<g[i].size();++a){
			for (b=a+1;b<g[i].size();++b){
				u=g[i][a].first,v=g[i][b].first;
				wt=g[i][a].second+g[i][b].second;
				f[u][v]=f[v][u]=min(f[u][v],wt);
//				cout<<u<<" "<<v<<" "<<wt<<'\n';
			}
		}
	}
	floyd();
	ll res=INF;
	for (int i=1,ut,vt;i<=q;++i){
		cin >> ut >> vt;
		res=INF;
		for (int a=0,b;a<g[ut].size();++a){
			for (b=0;b<g[vt].size();++b){
//				u=g[ut][a].first,v=g[vt][b].first;
				res=min(res,f[g[ut][a].first][g[vt][b].first]+g[ut][a].second+g[vt][b].second);
			}
		}
		cout<<res+w[ut]+w[vt]<<'\n';
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> cid;//这里就输入了c
	int T=1;
//	cin >> T;
	for (int _=0;_<T;++_) solve();
	cout.flush();
	return 0;
}
//这个w是干啥的
//一个人在地铁上可以瞬移到另一个站点
//那么，每个站点不就是很多个地铁的交换吗
//在这里连完全图就完了（？）
//然后跑floyd，就没了？

//感谢大样例，帮我测出const int INF=1e18
//这里写成int了
//15:03