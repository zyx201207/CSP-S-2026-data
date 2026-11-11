#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+5,M=6e5+5,inf=1e18;
int c,n,m,d,qq,w[M],dis[M],to[N][N];
struct edge{
	int v,w;
};
vector<edge>mp[M];
int themp[N][N];
struct node{
	int x,k;
	friend bool operator < (node x,node y){
		return x.k<y.k;
	}
	friend bool operator > (node x,node y){
		return x.k>y.k;
	}
};
priority_queue<node,vector<node>,greater<node> >q;
void dij(int s){
	for(int i=1;i<=n;i++) dis[i]=inf;
	q.push({s,0});dis[s]=0;
	while(!q.empty()){
		node x=q.top();q.pop();
		if(x.k!=dis[x.x]) continue;
		for(int i=1;i<=n;i++){
			if(dis[i]>dis[x.x]+themp[x.x][i]) dis[i]=dis[x.x]+themp[x.x][i],q.push({i,dis[i]});
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;cin>>x>>y;
			mp[x].push_back({m+i,y});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) themp[i][j]=inf;
	for(int i=1;i<=m;i++){
		for(int j=0;j<mp[i].size();j++){
			for(int k=0;k<mp[i].size();k++){
				if(j==k) continue;
				int v1=mp[i][j].v-m,v2=mp[i][k].v-m,w1=mp[i][j].w,w2=mp[i][k].w;
				themp[v1][v2]=min(themp[v1][v2],w1+w2);
				themp[v2][v1]=min(themp[v2][v1],w1+w2);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
		for(int j=1;j<=n;j++) to[i][j]=dis[j];
	}
	while(qq--){
		int u,v;cin>>u>>v;
		int ans=inf;
		for(int i=0;i<mp[u].size();i++){
			for(int j=0;j<mp[v].size();j++){
				ans=min(ans,mp[u][i].w+mp[v][j].w+to[mp[u][i].v-m][mp[v][j].v-m]);
			}
		}
		cout<<ans+w[u]+w[v]<<"\n";
	}
	return 0;
}

