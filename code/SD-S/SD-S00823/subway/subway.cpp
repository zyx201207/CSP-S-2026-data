#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const int inf=0x3f3f3f3f;
const i64 INF=0x3f3f3f3f3f3f3f3f;
const int N=5e2+5;
const int M=5e5+5;
int n,m,d,q;
int w[M],k[N];
vector<pii> t[N],mp[M];
i64 dist[M];
void bfs(int x,int y){
	memset(dist,INF,sizeof(dist));
	dist[x]=0;
	queue<int> q;
	q.push(x);
	while(q.size()){
		int u=q.front();
		q.pop();
		for(auto v:mp[u]){
			int xx=v.first,yy=v.second;
			if(dist[xx]!=INF){
				continue;
			} 
			dist[xx]=dist[u]+yy;
			q.push(xx);
		}
	}
	i64 ans=1LL*w[x]+w[y]+dist[y];
	cout<<ans<<"\n";
}
void solve(){
	int c;
	cin>>c;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x;
			cin>>x;
			int ny;
			cin>>ny;
			t[i].push_back({x,ny});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			for(int k1=j+1;k1<k[i];k1++){
				mp[t[i][j].first].push_back({t[i][k1].first,t[i][j].second+t[i][k1].second});
				mp[t[i][k1].first].push_back({t[i][j].first,t[i][j].second+t[i][k1].second});
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		bfs(x,y);
	}
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
