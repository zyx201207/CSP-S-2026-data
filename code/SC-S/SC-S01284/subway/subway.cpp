#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define inl inline
const int N=5e5+10;
using namespace std;
int c,n,m,d,q;
int p[N],k[505],vis[N+500],dis[N+500],dis2[1505][1505];
vector<pii> e[N+500];
inl void dij(int s){
	for(int i=0;i<=n+m;i++){
		dis[i]=1e18;
		vis[i]=0;
	}
	priority_queue<pii,vector<pii>,greater<pii>> q;
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		pii x=q.top();q.pop();
		int u=x.second,t=x.first;
		if(vis[u])continue;
		vis[u]=1;
		for(auto xx:e[u]){
			int v=xx.first,w=xx.second;
			if(!vis[v]&&dis[v]>t+w){
				dis[v]=t+w;
				q.push({t+w,v});
			}
		}
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			e[a].push_back({m+i,t});
			e[m+i].push_back({a,t});
		}
	}
	if(q<=2000){
		while(q--){
			int x,y;
			cin>>x>>y;
			dij(x);
			cout<<p[x]+p[y]+dis[y]<<endl;
		}
	}else{
		for(int i=1;i<=m;i++){
			dij(i);
			for(int j=1;j<=m;j++){
				dis2[i][j]=dis[j];
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<p[x]+p[y]+dis2[x][y]<<endl;
		}
	}
	return 0;
}