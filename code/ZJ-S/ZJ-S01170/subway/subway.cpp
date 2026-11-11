#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N=505;
const int M=5e5+5;
const int INF=0x3f3f3f3f3f3f3f3f;

int c,n,m,d,q;

int w[M];

struct B{
	int v,t;
};

vector<B> g[N+M];

int dis[M+N];

struct node{
	int u,t;
	bool operator<(node x)const{
		return t>x.t;
	}
};

int dj(int st,int ed){
	for(int i=1;i<=n+m;i++) dis[i]=INF;
	dis[st]=0;
	
	priority_queue<node> q;
	q.push({st,0});
	
	while(q.size()){
		int u=q.top().u;
		int tt=q.top().t;
		q.pop();
		
//		cout<<u<<" "<<tt<<"\n";
		
		if(tt>dis[u]) continue;
		
		for(auto [v,t]:g[u]){
			int cnt=tt+t;
			if(dis[v]>cnt){
				dis[v]=cnt;
				q.push({v,cnt});
			}
		}
	}
	
//	cout<<w[st]<<" "<<w[ed]<<"\n";
	
	return dis[ed]+w[st]+w[ed];
}

void solve1(){
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			g[m+i].push_back({x,t});
			g[x].push_back({m+i,t});
		}
	}
	
//	for(int i=1;i<=m+n;i++){
//		cout<<i<<":\n";
//		for(auto [v,t]:g[i]){
//			cout<<v<<" "<<t<<"\n";
//		}
//	}
	
	while(q--){
		
		int u,v;
		cin>>u>>v;
		
		cout<<dj(u,v)<<"\n";
		
	}
	
	return;
}

signed main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	
	if(c<=8){
		solve1();
	}else{
		solve1();
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/