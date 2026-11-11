#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;

ll c, n, m, d, q;
ll w[N];
ll a[505][2005];
ll t[505][2005];
struct node{
	int xian,zhan,val;
};
vector<node> z[N];
vector<node> g[N];
vector<bool> zhuan(N);
ll bfs(node x,node y){
	vector<bool> vis(N);
	vector<ll> dis(N,N);
	queue<node> q;
	q.push({x.xian,x.zhan,x.val});
	vis[x.val]=1;
	dis[x.val]=w[x.val];
	while(!q.empty()){
		node f=q.front();
		int u=f.val;
		int ux=f.xian;
		int uz=f.zhan;
		vis[u]=1;
		//cout<<u<<" "<<dis[u]<<"->";
		q.pop();
		for(int i=0;i<(int)g[u].size();i++){
			int v=g[u][i].val;
			if(!vis[v] && v!=0){
				dis[v]=min(dis[v],dis[u]+t[g[u][i].xian][g[u][i].zhan]);
				if(g[u][i].xian!=ux&&zhuan[u]){
					dis[v]+=t[ux][uz];
				}
				//cout<<u<<" "<<dis[u]<<"->"<<v<<" "<<dis[v]<<" \n";
				q.push({g[u][i].xian,g[u][i].zhan,v});
			}
		}
	}
	//cout<<"\n";
	return dis[y.val]+w[y.val];
}
int main(){
	freopen("subway.in","r",stdin);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			
			z[a[i][j]].push_back({i,j,a[i][j]});
			if(z[a[i][j]].size()>1){
				zhuan[a[i][j]]=1;
			}
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<j;l++){
				g[a[i][j]].push_back({i,j-l,a[i][j-l]});
				g[a[i][j-l]].push_back({i,j,a[i][j]});
			}
		}
		
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=N*N;
		for(int i=0;i<(int)z[x].size();i++){
			for(int j=0;j<(int)z[y].size();j++){
				if(z[x][i].xian==z[y][j].xian){
					ans = min(ans,w[x]+w[y]+t[z[x][i].xian][z[x][i].zhan]+t[z[y][j].xian][z[y][j].zhan]);
				}
			}
		}
		if(ans < N)
			cout<<ans<<"\n";
			
		else{
			for(int i=0;i<(int)z[x].size();i++){
				for(int j=0;j<(int)z[y].size();j++){
					if(z[x][i].xian!=z[y][j].xian) ans = min(bfs({z[x][i].xian,z[x][i].zhan,z[x][i].val},{z[y][j].xian,z[y][j].zhan,z[y][j].val}),ans);
				}
			}
			cout<<ans<<"\n";
		}
		
	}
	freopen("subway.out","w",stdout);
	return 0;
} 