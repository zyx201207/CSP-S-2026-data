#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=1e18;
struct node{
	int v,w;
};
struct edge{
	int id,val;
	bool operator<(const edge x)const{
		x.val>val;
	}
};
int c,n,m,d,q,w[N],f[N+500],vis[N+500],ans[1005][1005],p,o=-1;
vector<node> vec[N+500];
priority_queue<edge> t;
queue<int> tt;
void dijkstra(int s){
	for(int i=1;i<=n+m;i++){
		f[i]=M;
	}
	f[s]=0;
	t.push({s,0});
	while(!t.empty()){
		int u=t.top().id;
		t.pop();
		for(int i=0;i<vec[u].size();i++){
			int v=vec[u][i].v;
			int w=vec[u][i].w;
			if(f[v]>f[u]+w){
				f[v]=f[u]+w;
				t.push({v,f[v]});
			}
		}
	} 
}
void dfs(int x,int cnt){
	if(cnt<f[x]){
		f[x]=cnt;
		for(int i=0;i<vec[x].size();i++){
			dfs(vec[x][i].v,cnt+1);
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			if(o==-1){
				o=t;
			}
			else if(o!=t){
				p=1;
			}
			vec[a].push_back({m+i,t});
			vec[m+i].push_back({a,t});
		}
	}
	
	if(p==0){
		while(q--){
			int x,y;
			cin>>x>>y;
			for(int i=1;i<=n+m;i++){
				f[i]=M;
			}
			dfs(x,0);
			cout<<f[y]*o+w[x]+w[y]<<"\n";
		}
		return 0;
	}
	
	for(int i=1;i<=m;i++){
		dijkstra(i);
		for(int j=1;j<=m;j++){
			ans[i][j]=f[j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<ans[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
} 
