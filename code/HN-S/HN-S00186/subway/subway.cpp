#include<bits/stdc++.h>
#define ll long long 
#define PI pair<ll,int>

using namespace std;
const int N=550;
const int M=5e5+10;

int c,n,m,d,q;
int w[M];
ll dis[N][N];

vector<PI>g[N];
bool vis[M];

void spfa(int s){
	priority_queue<PI,vector<PI>,greater<PI> >q;
	q.push({0,s});
	for(int i=1;i<=n;++i){
		dis[s][i]=1e18;
	}
	for(int i=1;i<=n;++i){
		vis[i]=false;
	}
	dis[s][0]=w[s];
//	vis[s]=true;
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u]==true){
			continue;
		}
		vis[u]=true;
		for(int i=0;i<g[u].size();++i){
			ll w_x=g[u][i].second;
			ll x=g[u][i].first;
			ll new_dis=w_x;
			if(dis[s][u]!=1e18){
				new_dis+=dis[s][u];
			}
			if(dis[s][x]>new_dis){
				dis[s][x]=new_dis;
				q.push({new_dis,x});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>m>>n>>d>>q;
	
	for(int i=1;i<=n;++i){
		cin>>w[i];
	}
	
	for(int i=1;i<=m;++i){
		int k;
		cin>>k;
		
		for(int j=1;j<=k;++j){
			int x;
			cin>>x;
			g[j].push_back({i,x});
			g[i].push_back({j,x});
		}
	}
	
	for(int i=1;i<=n;++i){
		spfa(i);
	}
	
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<dis[l][r]<<"\n";
	}
	
	return 0;
}
