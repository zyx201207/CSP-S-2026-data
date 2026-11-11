#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=5e5+10,N=500;
int w[M];
bool vis[N][N];
vector<pair<int,ll>> stops[M];
ll dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		while(k--){
			int a;ll t;cin>>a>>t;
			stops[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	queue<pair<int,int>> qu;
	for(int i=1;i<=m;i++)
		for(auto u:stops[i])for(auto v:stops[i])
			if(dis[u.first][v.first]>u.second+v.second){
				dis[u.first][v.first]=u.second+v.second;
				if(!vis[u.first][v.first])
					qu.push({u.first,v.first}),
					vis[u.first][v.first]=1;
			}
	while(!qu.empty()){
		auto p=qu.front();qu.pop();int i=p.first,k=p.second;
		vis[i][k]=0;
		for(int j=1;j<=n;j++)
			if(dis[i][j]>dis[i][k]+dis[k][j]){
				dis[i][j]=dis[i][k]+dis[k][j];
				if(!vis[i][j])
					qu.push({i,j}), vis[i][j]=1;
			}
	}
	while(q--){
		int x,y; cin>>x>>y;
		ll ans=LLONG_MAX;
		for(auto u:stops[x]) for(auto v:stops[y])
			ans=min(u.second+dis[u.first][v.first]+v.second,ans);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
