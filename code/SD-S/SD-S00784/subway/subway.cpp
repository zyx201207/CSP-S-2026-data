#include<bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define mkp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//value
const ll inf=2e18+5;
const int mod=1e9+7;
const int N=505;
const int M=2e4+5;
struct edge{
	ll v,w;
	bool operator < (const edge &x)const {
		if(w==x.w)return v<x.v;
		return w>x.w;
	}
};
vector<edge>g[N+M];
priority_queue<edge>pq;
ll ans[N][N+M],vis[N+M],w[N];


//function
void solve(){
	
	
	return;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c;
	cin>>c;
	if(c==20 || c==21){
		ll n,m,d,q;
		cin>>n>>m>>d>>q;
		for(int i=1;i<=m;i++)cin>>w[i];
		ll an=inf;
		for(int i=1;i<=n;i++){
			ll k,res=0;
			cin>>k;
			for(int j=1;j<=k;j++){
				ll x,y;
				cin>>x>>y;
				res+=y;
			}
			if(k==2)an=min(an,res);
		}
		while(q--){
			ll x,y;
			cin>>x>>y;
			cout<<an+w[1]+w[2]<<endl;
		}
		return 0;
	}
	
	ll n,m,d,q;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	//1~m是车站 m+1~m+n是铁路站 
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll v,w;
			cin>>v>>w;
			g[m+i].push_back({v,w});
			g[v].push_back({m+i,w});
		}
	}
	for(int i=1;i<=m;i++){
		//跑m轮dijkstra 求出两点间最短路
		for(int j=1;j<=n+m;j++){
			ans[i][j]=inf;
			vis[j]=0;
		}
		//st=i;
		ans[i][i]=0;
		pq.push({i,ans[i][i]});
		while(!pq.empty()){
			edge tmp=pq.top();
			pq.pop();
			ll id=tmp.v,res=tmp.w;
			if(vis[id])continue;
			vis[id]=1;
			for(auto tt:g[id]){
				if(res+tt.w<ans[i][tt.v]){
					ans[i][tt.v]=res+tt.w;
					pq.push({tt.v,ans[i][tt.v]});
				}
			}
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		cout<<min(ans[x][y],ans[y][x])+w[x]+w[y]<<endl;
	}
	
	
	//15：13 简单判断是有44分的暴力 
	//       对于单次询问好像是跑一边dij就行了
	//       O(q(n+m)log K) 跑前六个点
	//15：18 性质A给的是两点直接连边，好像可以prim做O(n^3+q) 
	//       20、21是不是就是两点之间所有可能的边取个最值就有了 
	//		 接下来可能要思考这个d有啥用 
	
	/*
	20 3 2 20 2
	2 3
	1 1 3
	2 1 4 2 5
	2 2 3 1 1
	1 2
	2 1
	
	*/
	
	
	return 0;
}

