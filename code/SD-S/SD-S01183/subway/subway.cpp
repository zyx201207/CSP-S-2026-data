#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#define ll long long
using namespace std;
typedef pair<int,int> P;
const int M=1e5+5,N=500+5;
int c,n,m,d,qu,k;
int w[M];
ll dis[N][N+M-5];
bool vis[N+M];
vector<P> v[N+M];
priority_queue<P,vector<P>,greater<P> > q;
inline void solve(){
	cin>>c>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		int x,t;
		while(k--){
			cin>>x>>t;
			v[i].emplace_back(n+x,t);
			v[n+x].emplace_back(i,t);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+m;j++) dis[i][j]=0x3f3f3f3f3f3f3f3f;
		for(int j=1;j<=n+m;j++) vis[j]=false;
		dis[i][i]=0;
		q.emplace(0,i);
		while(!q.empty()){
			P t=q.top(); q.pop();
			int x=t.second;
			if(vis[x]) continue;
			vis[x]=true;
			for(const P &it:v[x]){
				int j=it.first,w=it.second;
				if(dis[i][j]>dis[i][x]+w){
					dis[i][j]=dis[i][x]+w;
					q.emplace(dis[i][j],j);
				}
			}
		}
	}
	while(qu--){
		int x,y;
		cin>>x>>y;
		ll minn=9e18;
		for(int i=1;i<=n;i++) minn=min(minn,dis[i][x+n]+dis[i][y+n]);
		cout<<minn+w[x]+w[y]<<"\n";
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
