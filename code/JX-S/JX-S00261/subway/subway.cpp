#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 7005,M = 5e5+5;
int c,n,m,d,qq,w[N];
int a[N],t[N],dis[N][N],vis[N];
struct nod{
	int v,w;
	bool operator < (const nod &a) const{
		return w>a.w;
	}
};
vector<nod> g[N];
priority_queue<nod> q;
void diji(int x){
	dis[x][x] = 0ll;
	memset(vis,0ll,sizeof vis);
	q.push({x,0ll});
	while(q.size()){
		int tmp = q.top().v;
		q.pop();
		if(vis[tmp]) continue;
		vis[tmp] = 1;
		for(int i = 0;i<g[tmp].size();i++){
			int v = g[tmp][i].v,w = g[tmp][i].w;
			if(dis[x][v]>dis[x][tmp]+w){
				dis[x][v] = dis[x][tmp]+w;
				q.push({v,dis[x][v]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>qq;
	for(int i = 1;i<=m;i++) cin>>w[i];
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		for(int j = 1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j = 1;j<=k;j++){
			for(int l = j+1;l<=k;l++){
				g[a[j]].push_back({a[l],t[j]+t[l]});
				g[a[l]].push_back({a[j],t[j]+t[l]});
			}
		}
	}
	for(int i = 1;i<=m;i++) diji(i);
	while(qq--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
//don't write n,m wrong!!
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 10
3 2 6 3 1 7 254 3 2 5 100 4 6 6 761 672 3 
*/
