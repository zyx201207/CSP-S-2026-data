#include<bits/stdc++.h>
#define int long long
#define N 210
#define M 410
#define pll pair <int,int>
using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
struct node {
	int l,u,w;
	friend bool operator < (const node &x,const node &y){
		return x.w>y.w;
	}
};
vector <int> pos[M];  //第 v 个地铁站经过哪些路线 
priority_queue <node> q;
vector <pll> ve[N][M];
bool f[N][M];
int c;
int n,m,d,Q,u,v,w,W[M],k[N],a[N][M],t[N][M],dis[N][M],ans;
void dijkstra (){
	while (!q.empty ()){
		node h=q.top (); q.pop ();
		if (f[h.l][h.u]){
			continue;
		}
		f[h.l][h.u]=1;
		for (auto i:ve[h.l][h.u]){
			int v=i.first,w=i.second;
			if (dis[h.l][v]>dis[h.l][h.u]+w){
				dis[h.l][v]=dis[h.l][h.u]+w;
				q.push ({h.l,v,dis[h.l][v]});
			}
		}
		for (auto i:pos[h.u]){
			if (dis[i][h.u]>dis[h.l][h.u]){
				dis[i][h.u]=dis[h.l][h.u];
				q.push ({i,h.u,dis[i][h.u]});
			}
		}
	}
	return ;
}
void solve (){
	cin>>u>>v;
	memset (f,0,sizeof f);
	memset (dis,0x3f,sizeof dis);
	for (auto i:pos[u]){
		q.push ({i,u,0});
		dis[i][u]=0;
	}
	dijkstra ();
	ans=9e18+162;
	for (auto i:pos[v]){
		ans=min (ans,dis[i][v]);
	}
	cout<<ans+W[u]+W[v]<<"\n";
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio (0);
	cin.tie (0); cout.tie (0);
	cin>>c>>n>>m>>d>>Q;
	for (int i=1; i<=m; i++){
		cin>>W[i];
	}
	for (int i=1; i<=n; i++){
		cin>>k[i];
		for (int j=1; j<=k[i]; j++){
			cin>>a[i][j]>>t[i][j];
			pos[a[i][j]].push_back (i);
			for (int k_=1; k_<j; k_++){
				ve[i][a[i][j]].push_back ({a[i][k_],t[i][j]+t[i][k_]});
				ve[i][a[i][k_]].push_back ({a[i][j],t[i][j]+t[i][k_]});
			}
		}
	}
	while (Q--){
		solve ();
	}
	return 0;
}
