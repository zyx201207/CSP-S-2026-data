#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[500005],c,n,m,d,q,a[1005][1005],ans,vis[200005],jl[200005];
vector<pair<int,int> >edge[600005];
vector<int>e[600005];
void dfs(int u,int fa,int v,int sum){
	if(u==v){
		ans=min(ans,sum);
	}
	for(auto nx:edge[u]){
		if(nx.first==fa)continue;
		dfs(nx.first,u,v,sum+nx.second);
	}
}
queue<int>Q,cl;
int bfs(int s,int t){
	for(int i=1;i<=n+m;i++){
		vis[i]=0;
		jl[i]=0;
	}
	Q=cl;
	Q.push(s);
	jl[s]=0;
	while(Q.size()){
		int u=Q.front();
		if(u==t){
			break;
		}
		Q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto v:e[u]){
			if(vis[v])continue;
//			cout<<u<<"->"<<v<<'\n';
			jl[v]=jl[u]+1;
			Q.push(v);
		}
	}
	return jl[t];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q; 
	if(c==9||c==10||c==11||c==22||c==23){
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=n;i++){
			int k,x,y;
			cin>>k;
			for(int j=1;j<=k;j++){
				cin>>x>>y;
				edge[i+m].push_back({x,y});
				edge[x].push_back({i+m,y});
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			ans=LONG_LONG_MAX;
			dfs(x,-1,y,0);
			cout<<ans+w[x]+w[y]<<'\n';
		}
		return 0;
	}
	if(c>=12&&c<=19){
		int qz=0;
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int x,y;
				cin>>x>>y;
				qz=y;
				e[i+m].push_back(x);
				e[x].push_back(i+m);
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<bfs(x,y)*qz+w[x]+w[y]<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(a,0x3f,sizeof a);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int A,T;
			cin>>A>>T;
			a[A][i+m]=T;
			a[i+m][A]=T;
		}
	}
	for(int i=1;i<=m;i++)a[i][i]=0;
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<=n+m;j++){
				if(a[i][k]+a[k][j]<a[i][j]){
					a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<a[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
