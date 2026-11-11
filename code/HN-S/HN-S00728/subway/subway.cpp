#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=500+5,M=5e5+5;
int c,n,m,d,q;
int w[M];
long long dis[N][N];
bool b[M];
int ans=1e9+7;
vector<pair<int , long long> > g[M],e[N];
void dij(int p){
	priority_queue<pair<long long ,int > ,vector<pair<long long,int > >,less<pair<long long ,int > > >q;
	 q.push({0,p});
	rep(i,1,n){
		dis[p][i]=1e18;
		b[i]=0;
	}
	dis[p][p]=0;
	while(!q.empty()){
		int u=q.top().second;
	//	cout<<q.top().first<<'\n'; 
		//cout<<u<<'\n';
		q.pop();
		if(b[u])continue;
		b[u]=1;
		for(auto i:e[u]){
			if(dis[p][i.first]>dis[p][u]+i.second)
			{
				dis[p][i.first]=dis[p][u]+i.second;
				q.push({dis[p][i.first],i.first});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m)cin>>w[i];
	rep(i,1,n){
		int k;
		cin>>k;
		int u,last=0,t;
		rep(j,1,k){
			cin>>u>>t;
			g[u].push_back({i,t});
		}
	}
	rep(i,1,m){
		if(g[i].size()>1){
			for(auto j:g[i]){
				for(auto k:g[i]){
					if(j.first==k.first)continue;
					e[j.first].push_back({k.first,j.second+k.second});
					e[k.first].push_back({j.first,j.second+k.second});
				}
			}
		}
	}
	rep(i,1,n){
		dij(i);
	//	rep(j,1,n)cout<<dis[i][j]<<' ';
	//	cout<<'\n';
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(auto i:g[x]){
			for(auto j:g[y]){
			//	cout<<i.first<<j.first<<'\n';
				ans=min(ans,(long long)i.second+j.second+dis[i.first][j.first]+w[x]+w[y]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//666
