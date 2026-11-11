#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e4+10,INF=1e18;
struct P{
	int u,w;
};
vector<P>g[N];
int c,n,m,d,qu,k[505],a[505][N],t[505][N],sta[N],maki,dis[N],vis[N];
priority_queue<P>q;
bool operator < (const P &qqq,const P &hhh){
	return qqq.w>hhh.w;
}
void dij(int x){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	q.push({x,0});
	vis[x]=1;
	dis[x]=0;
	while(q.size()){
		int now=q.top().u;
		q.pop();
		vis[now]=1;
		for(auto e:g[now]){
			int v=e.u,w=e.w;
			if(dis[v]>dis[now]+w){
				dis[v]=dis[now]+w;
				if(vis[v]){
					continue;
				}
				q.push({v,dis[v]});
			}
		}
	}
}
void solve1(){
	for(int i=1;i<=n;i++){
		for(int l=1;l<=k[i];l++){
			for(int r=l+1;r<=k[i];r++){
				g[a[i][l]].push_back({a[i][r],t[i][l]+t[i][r]});
				g[a[i][r]].push_back({a[i][l],t[i][l]+t[i][r]});
			}
		}
	}
	while(qu--){
		int ss,ff;
		cin>>ss>>ff;
		dij(ss);
		cout<<dis[ff]+sta[ss]+sta[ff]<<endl;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++){
		cin>>sta[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		maki=max(maki,k[i]);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	solve1();
	return 0;
}
