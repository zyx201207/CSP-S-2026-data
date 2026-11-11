#include<bits/stdc++.h>
using namespace std;
const int N=2e5+200,inf=1e9+10;
struct edge{int v,id;};
struct node{
	int to,tim,id;
	bool operator<(const node &rhs)const{
		return rhs.tim<tim;
	}
};
int c,n,m,d,T;
int w[N],a[505][N],t[505][N],mp[N][505],k[N];
bool vis[505][N];
vector<edge>g[N];
priority_queue<node>q;
int bfs(int s,int e){
	int minn=inf,min_id;
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)vis[i][j]=0;
	for(int i=1;i<=n;i++)if(mp[s][i])q.push({s,t[i][mp[s][i]]+w[s],i});
	while(!q.empty()){
		auto [u,tim,id]=q.top();
		q.pop();
		if(u==0||vis[id][u])continue;
		if(u==e)return tim+w[e]+t[id][mp[e][id]];
		vis[id][u]=1;
		for(auto [v,_id]:g[u]) {
			if(id==_id)q.push({v,tim,_id});
			else q.push({v,t[_id][mp[u][_id]]+t[id][mp[u][id]]+tim,_id});
		}
	}
	return -1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			mp[a[i][j]][i]=j;
			g[a[i][j]].push_back({a[i][j-1],i}),g[a[i][j-1]].push_back({a[i][j],i});
		}
	}
	while(T--){
		int s,e;
		cin>>s>>e;
		cout<<bfs(s,e)<<'\n';
	}
	return 0;
}
