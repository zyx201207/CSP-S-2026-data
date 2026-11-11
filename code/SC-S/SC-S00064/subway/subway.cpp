#include<bits/stdc++.h>
#define ll long long
using namespace std;

//其实打个车步数不就一直是0了吗 
const int NM = 5e5;
const ll INF = 1e18;
int c,n,m,d,q;
int W[NM+4],T[NM+4][500+4];
set<int> F[NM+4];
vector<pair<int,int>> E[NM+4];
struct sle{
	ll val;
	int id,line;
};
bool operator<(const sle &x,const sle &y){
	return x.val < y.val; 
}
ll dij(int s,int e){
	vector<ll> dis(m+4,INF);
	vector<bool> vis(m+4,0);
	priority_queue<sle> Q;
	for(const int &id : F[s]) Q.push({-W[s]-T[s][id],s,id});
	while(Q.size()){
		int x = Q.top().id,line = Q.top().line;
		ll value = Q.top().val;
		Q.pop();
		if(vis[x]) continue;
		dis[x] = -value;
		vis[x] = 1;
		for(auto &point : E[x]){
			int y = point.first,ly = point.second;
			if(y == e) return dis[x]+T[y][line]+W[y];
			ll w = 0;
			if(ly != line) w = 1ll*T[y][line]+T[y][ly];
			if(dis[y] > dis[x]+w) dis[y] = dis[x]+w,Q.push({-dis[y],y,ly});
		}
	} 
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++) cin>>W[i];
	int last = -1;
	for(int i = 1;i <= n;i++){
		int k;cin>>k;
		for(int j = 1;j <= k;j++){
			int a;cin>>a>>T[a][i];
			F[a].insert(i);
			if(j == 1){
				last = a;
				continue;
			}
			E[a].push_back({last,i}),E[last].push_back({a,i});
			last = a;
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		cout<<dij(x,y)<<'\n';
	}
	return 0;
}
