#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=505,M=5e5+5,INF=1e18;
ll c,n,m,d,q,w[M],f[N][N];
struct note{
	ll id,dis;
	bool operator < (const note&x) const{
		return dis>x.dis;
	}	
};
vector<note> vec[M],vec2[N];
bool vis[N];
void dijkstra(ll x){
	f[x][x]=0;
	for(int i=1;i<=n;i++) vis[i]=0;
	priority_queue<note> pq; pq.push({x,0});
	while(!pq.empty()){
		note now=pq.top(); pq.pop();
		if(vis[now.id]) continue; vis[now.id]=1;
		for(int i=0;i<vec2[now.id].size();i++){
			note nxt=vec2[now.id][i];
			if(f[x][now.id]+nxt.dis<f[x][nxt.id]){
				f[x][nxt.id]=f[x][now.id]+nxt.dis;
				pq.push({nxt.id,f[x][nxt.id]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){
			int a,t; cin>>a>>t;
			for(int p=0;p<vec[a].size();p++){
				ll now=vec[a][p].id,v=vec[a][p].dis;
				vec2[now].push_back({i,v+t});
				vec2[i].push_back({now,v+t});
//				cout<<"build : "<<now<<" "<<i<<" "<<v+t<<endl;
			}
			vec[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=INF;
	for(int i=1;i<=n;i++) dijkstra(i);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			cout<<f[i][j]<<" ";
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++){
		ll x,y,ans=INF; cin>>x>>y;
		for(int j=0;j<vec[x].size();j++){
			ll val1=vec[x][j].dis,nt1=vec[x][j].id;
			for(int k=0;k<vec[y].size();k++){
				ll val2=vec[y][k].dis,nt2=vec[y][k].id;
				ans=min(ans,f[nt1][nt2]+val1+val2);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
