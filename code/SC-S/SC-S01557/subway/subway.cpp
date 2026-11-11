#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using pii=pair<int,int>;
const ull INF=(((1ULL<<63)-1)<<1)+1;
const int MAXN=500;
const int MAXM=5e5;
const int MAXNODE=1e7+1e6+5;
int c,n,m,d,q;
int cnt=0;
vector<pii> g[MAXNODE];
ull dis[MAXNODE];
struct cmp{
	bool operator()(int a,int b){
		return dis[a]>dis[b];
	}
};
int dij(int s,int t){
	priority_queue<int,vector<int>,cmp> pq;
	for(int i=0;i<cnt;i++)
		dis[i]=INF;
	dis[s]=0;
	pq.push(s);
	while(!pq.empty()){
		int u=pq.top(); pq.pop();
		if(u==t) break;
		for(const auto &[v,w]:g[u]){
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				pq.push(v);
			}
		}
	}
	return dis[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
//	if(!((n<=200 && m<=5e5) || (n<=2 && m<=2e4))){ // 优化了存储, 不再需要
//		cout<<"is too big for this program qwq\nOvO\n";
//		return 0;
//	}
	cnt=2*m;
	for(int i=0;i<m;i++){
		int w;
		cin>>w;
		g[i].push_back({m+i,w});
		g[m+i].push_back({i,w});
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		int lsta,a,t;
		cin>>lsta>>t;
		lsta--;
		g[m+lsta].push_back({cnt,t});
		g[cnt++].push_back({m+lsta,t});
		for(int j=1;j<k;j++){
			cin>>a>>t;
			a--;
			g[cnt].push_back({cnt-1,0});
			g[cnt-1].push_back({cnt,0});
			g[m+a].push_back({cnt,t});
			g[cnt++].push_back({m+a,t});
			lsta=a;
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		cout<<dij(s-1,t-1)<<'\n';
	}
	return 0;
}