#include<bits/stdc++.h>
#define int long long
#define pi pair<int,int>
#define fi first
#define se second
using namespace std;
const int INF=1000000000000;
struct node{
	int li,cost;
};
struct nd{
	int to,cost;
};
int c,n,m,dd,q,a[500005],T;
vector<nd> line[505];
vector<node> e[300005];
int d[500005],vis[500005];
void solve(int x,int y){
	priority_queue<pi,vector<pi>,greater<pi>> q;
	for(int i=1;i<=m;i++){
		d[i]=INF;
		vis[i]=false;
	}d[x]=0;
	q.push({0,x});
	while(!q.empty()){
		int now=q.top().se;
		q.pop();
		if(vis[now]) continue;
		vis[now]=true;
		if(now==y){
			cout<<d[now]+a[x]+a[y]<<'\n';
			return ;
		}for(int i=0;i<(int)e[now].size();++i){
			int l=e[now][i].li,c1=e[now][i].cost;
			for(int j=0;j<(int)line[l].size();++j){
				int u=line[l][j].to,v=line[l][j].cost;
				if(u==now) continue;
				if(d[u]>d[now]+c1+v){
					d[u]=d[now]+c1+v;
					q.push({d[u],u});
				}
			}
		}
	}return ;
}void solve1(int x,int y){
	queue<pi> q;
	for(int i=1;i<=m;i++){
		d[i]=INF;
		vis[i]=false;
	}q.push({0,x});
	while(!q.empty()){
		int now=q.front().se;
		q.pop();
		if(vis[now]) continue;
		vis[now]=true;
		if(now==y){
			cout<<d[now]*T+a[x]+a[y]<<'\n';
			return ;
		}for(int i=0;i<(int)e[now].size();++i){
			int l=e[now][i].li;
			for(int j=0;j<(int)line[l].size();++j){
				int u=line[l][j].to;
				if(u==now) continue;
				if(d[u]>d[now]+2){
					d[u]=d[now]+2;
					q.push({d[u],u});
				}
			}
		}
	}return ;
}signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>q;
	int mark=0;
	if(12<=c&&c<=19) mark=1;
	for(int i=1;i<=m;++i) cin>>a[i];
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int u,v;
			cin>>u>>v;
			T=v;
			line[i].push_back({u,v});
			e[u].push_back({i,v});
		}
	}while(q--){
		int u,v;
		cin>>u>>v;
		if(mark==1) solve1(u,v);
		else solve(u,v);
	}return 0;
}
