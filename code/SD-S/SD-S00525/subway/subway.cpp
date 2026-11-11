#include<bits/stdc++.h>
using namespace std;
using PI=pair<int,int>;
const int N=510,M=5e5+10,INF=0x3f3f3f3f;
int C,n,m,D,Q;
int a[N];
int h[M],e[M*40+10],ne[M*40+10],w[M*40+10],idx=1;
vector<PI>edge[M];//线路信息 
vector<PI>bel[N];
bitset<M>bs[N];//每个站点所属的线路情况 
//map<PI,int>g;//邻接矩阵 
int dis[M];
//bitset<M>g[N];
bool f[M];
int res=INF;
inline void add(int a,int b,int l){
	e[idx]=b;
	ne[idx]=h[a];
	w[idx]=l;
	h[a]=idx++;
}
void bfs(int st,int ed){
	priority_queue<PI,vector<PI>,greater<PI>>q;
//	f[st]=1;
	memset(dis,0x3f,sizeof dis);
	q.push({0,st});
	dis[st]=0;
	while(q.size()){
		int x=q.top().second,s=q.top().first;
		q.pop();
		if(f[x]){
			continue;
		}
		f[x]=1;
		for(auto i:bel[x]){
			for(auto j:edge[i.first]){
				if(j.first!=x&&!f[j.first]){
					dis[j.first]=dis[i.first]+i.second+j.second;
					q.push({s+i.second+j.second,j.first});
//					f[j.first]=1;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>m>>n>>D>>Q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=m;++i){
		int k;
		cin>>k;
		while(k--){
			int x,y;
			cin>>x>>y;
			edge[i].push_back({x,y});
			bel[x].push_back({i,y});
			bs[x].set(i);
		}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		res=INF;
		bfs(x,y);
		cout<<dis[y]<<"\n";
	}
	return 0;
}

