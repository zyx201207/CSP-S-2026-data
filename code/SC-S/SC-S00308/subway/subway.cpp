#include<bits/stdc++.h>
#include <queue>
using namespace std;
const int MAXN=505+5,MAXM=5e5+5;
const long long INF=0x3f3f3f3f3f3f3f3f;
int c,d,q,n,m;
typedef pair<int,int> PII;
struct cmp{
	operator()(PII a,PII b) const{
		return a.second>b.second;
	}
};
priority_queue<PII,vector<PII>,cmp> pq;
map<int,int> mp[MAXN];
vector<int> vec[MAXM];
long long dis[MAXN][MAXN];
bool vis[MAXM];
int w[MAXM],k[MAXN];
//线路
void dij(int x){
	memset(vis,0,sizeof vis);
	vis[x]=1;
	dis[x][x]=0;
	pq.push({x,0});
	while(pq.size()){
		auto [u,w]=pq.top();pq.pop();
		for(int i=1;i<=n;i++){
			if(i==u)continue;
			if(dis[x][i]>=w+dis[u][i]){
				dis[x][i]=dis[u][i]+w;
				pq.push({i,dis[x][i]});
			}
		}
	}
}
//建造dis
void build(){
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			mp[a][i]=t;
			vec[i].push_back(a);
		}
	}
	for(int i=1;i<=n;i++){
		for(auto a:vec[i]){
			for(auto [xianlu,t]:mp[a]){
				if(xianlu==i)continue;
				dis[i][xianlu]=min(dis[i][xianlu],(long long)t+mp[a][i]);
				dis[xianlu][i]=dis[i][xianlu];
			}
		}
	}
}
int main(){
	memset(dis,0x3f,sizeof dis);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	build();
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=INF;
		for(auto [a,t]:mp[x]){
			if(dis[a][a]==INF){
				dij(a);
			}
			for(auto [b,w]:mp[y]){
				if(dis[a][b]+t+w<ans){
					ans=dis[a][b]+t+w;
				}
			}	
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}