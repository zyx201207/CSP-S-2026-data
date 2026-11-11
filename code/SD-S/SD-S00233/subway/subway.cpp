#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18
const int N=5e4+10;
const int M=510;
struct Node{
	int v,w,f;
};
struct Edge{
	int id,dist;
	bool operator<(const Edge &rhs)const{
		return dist>rhs.dist;
	} 
};
map<pair<int,int>,int>mp;
vector<Node>g[N];
int c,n,m,d,qq,vis[N];
int w[N],t[N][M];
int k[N],ans[N],x,y;
int l[M][N];
priority_queue<Edge>q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			int x,y;cin>>x>>y;
			l[i][j]=x;
			t[x][i]=y;
		}
		for(int j=1;j<=k[i];++j){
			for(int z=1;z<=k[i];++z){
				if(j==z)continue;
				int u=l[i][j],v=l[i][z];
				g[u].push_back({v,t[u][i]+t[v][i],i});
				g[v].push_back({u,t[u][i]+t[v][i],i});
			}
		}
	}
	for(int i=1;i<=m;++i){
		while(!q.empty())q.pop();
		q.push({i,0});
		for(int j=1;j<=m;++j)ans[j]=INF,vis[j]=0;
		ans[i]=0;
		while(!q.empty()){
			Edge u=q.top();q.pop();
			if(vis[u.id])continue;
			vis[u.id]=1;
			for(int j=0;j<g[u.id].size();++j){
				Node v=g[u.id][j];
				if(ans[v.v]>ans[u.id]+v.w){
					ans[v.v]=ans[u.id]+v.w;
					q.push({v.v,ans[v.v]});
				}
			}
		}
		for(int j=1;j<=m;++j)mp[{i,j}]=mp[{j,i}]=ans[j];
	}
	while(qq--){
		int x,y;cin>>x>>y;
		cout<<mp[{x,y}]+w[x]+w[y]<<endl;
	}
	return 0;
} 
